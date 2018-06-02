#include "Go2LLVMMyVisitor.h"

using namespace go_parser;
using namespace llvm;
using antlrcpp::Any;
using std::string;
using std::vector;
using std::pair;


/*
 * Function = func_tok ident_tok signature [block]
 * Return: nullptr | Function*
 */
Any Go2LLVMMyVisitor::visitFunctionDecl(Go2LLVMParser::FunctionDeclContext *ctx) {
    parser_errors.Log("visitFunctionDecl");

    // Function name
    string function_name = ctx->IDENT_TOK()->getText();

    Function *function = module->getFunction(function_name);
    if(function && function->getName() != "main") {
        return parser_errors.AddError(ctx->getStart()->getLine(), "Function " + function_name + " already defined");
    }

    // main function is defined already
    if(function_name != "main") {
        // Function signature - parameters and return types/variables
        pair<vector<Variable>, string> signature = ctx->signature()->accept(this);
        vector<Variable> arguments = signature.first;
        string return_type = signature.second;

        // Make the function type
        vector<Type*> argsTypes(arguments.size(), Type::getInt32Ty(context));
        FunctionType *function_type = FunctionType::get(Type::getInt32Ty(context), argsTypes, false);

        // Create function
        function = Function::Create(function_type, Function::ExternalLinkage, function_name, module);

        // Set arg names
        unsigned i = 0;
        for (auto &arg : function->args())
            arg.setName(arguments.at(i++).name);
    }

    // return if no function body
    if(ctx->block() == nullptr) {
        return nullptr;
    }

    // make entrypoint for initialization
    BasicBlock *entrypoint = BasicBlock::Create(context, function->getName()+"entrypoint", function);
    builder.SetInsertPoint(entrypoint);

    // entrypoint block will contain mutable arguments, they should be visible in whole function
    current_block = new MyBasicBlock(function, entrypoint, nullptr);

    for (auto &arg : function->args()) {
        // Create an alloca for the argument
        AllocaInst *alloca = builder.CreateAlloca(builder.getInt32Ty(), 0, arg.getName()+".addr");

        // Store the initial value into the alloca.
        builder.CreateStore(&arg, alloca);

        // Add arguments to variable symbol table.
        current_block->named_values[arg.getName()] = Variable(arg.getName(), "int32", alloca);
    }

    // make body, it will create new block under entrypoint
    Any any_ret_val = ctx->block()->accept(this);

    // Verify
    verifyFunction(*function);

    return function;
}

/*
 * Signature = parameters [result]
 * Return: pair<vector<Variable>, string> - identifiers (arguments) and return type
 */
Any Go2LLVMMyVisitor::visitSignature(Go2LLVMParser::SignatureContext *ctx) {
    parser_errors.Log("visitSignature");

    vector<Variable> parameters;
    string result;

    Any any_v = ctx->parameters()->accept(this);
    if(any_v.isNotNull()){
        parameters = any_v.as<vector<Variable>>();
    }

    if(ctx->result() != nullptr) {
        any_v = ctx->result()->accept(this);
        if(any_v.isNotNull())
            result = any_v.as<string>();
    }

    pair<vector<Variable>, string> signature = std::make_pair(parameters, result);
    return signature;
}

/*
 * Result = parameters | type
 * Return: string - type
 */
Any Go2LLVMMyVisitor::visitResult(Go2LLVMParser::ResultContext *ctx) {
    parser_errors.Log("visitResult");

    if(ctx->type() != nullptr) {
        return ctx->type()->accept(this);
    } else {
        // todo: handle list of params in result
        return nullptr;
    }
}

/*
 * Parameters = '(' [parameterList [',']] ')'
 * Return: nullptr | vector<Variable> - parameters
 */
Any Go2LLVMMyVisitor::visitParameters(Go2LLVMParser::ParametersContext *ctx) {
    parser_errors.Log("visitParameters");
    if(ctx->parameterList() != nullptr) {
        return ctx->parameterList()->accept(this);
    }
    return nullptr;
}

/*
 * ParameterList = parameterDecl { COMMA parameterDecl }
 * Return: vector<Variable> - parameters
 */
Any Go2LLVMMyVisitor::visitParameterList(Go2LLVMParser::ParameterListContext *ctx) {
    parser_errors.Log("visitParameterList");

    vector<Variable> identifiers;
    for(auto parameterDecl : ctx->parameterDecl()) {
        vector<Variable> identifiers_to_append = parameterDecl->accept(this);
        identifiers.insert(identifiers.end(), identifiers_to_append.begin(), identifiers_to_append.end());
    }
    return identifiers;
}

/*
 * ParameterDecl = identifielList type
 * Return: vector<Variable> - parameters
 */
Any Go2LLVMMyVisitor::visitParameterDecl(Go2LLVMParser::ParameterDeclContext *ctx) {
    vector<string> identifiers = ctx->identifierList()->accept(this);
    string type = ctx->type()->accept(this);

    vector<Variable> parameters;
    for(auto identifier : identifiers) {
        parameters.push_back(Variable(identifier, type));
    }
    return parameters;
}

