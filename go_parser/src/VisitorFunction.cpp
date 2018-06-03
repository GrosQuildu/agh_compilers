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

    // Function signature - parameters and return types/variables
    Any any_v = ctx->signature()->accept(this); if(any_v.isNull()) return nullptr;
    pair<vector<Variable>, Type*> signature = any_v;
    vector<Variable> arguments = signature.first;
    Type *return_type = signature.second;

    // Make the function signature
    vector<Type*> arg_types(arguments.size());
    for(auto &variable : arguments)
        arg_types.push_back(variable.type);
    FunctionType *function_type = FunctionType::get(return_type, arg_types, false);

    Function *function = module->getFunction(function_name);
    if(function) {
        // If function exists, check if signature it matches
        if(function->getFunctionType() != function_type) {
            return parser_errors.AddError(ctx->getStart()->getLine(),
                                          "Function " + function_name + " redefined with different signature");
        }
    } else {
        // Create function
        function = Function::Create(function_type, Function::ExternalLinkage, function_name, module);
    }

    // Set arg names
    unsigned i = 0;
    for (auto &arg : function->args())
        arg.setName(arguments.at(i++).name);

    // Return if no function body
    if(ctx->block() == nullptr) {
        return function;
    }

    // Make entrypoint block, main function already have entrypoint
    if(function->getName() != "main") {
        BasicBlock *entrypoint = BasicBlock::Create(context, function->getName() + " entrypoint", function);
        builder.SetInsertPoint(entrypoint);
    }

    // entrypoint block will contain mutable arguments, they should be visible in whole function
    current_block = new MyBasicBlock(function, nullptr);

    // Make store instruction for arguments
    for (auto &arg : function->args()) {
        // Create an alloca for the argument
        AllocaInst *alloca = builder.CreateAlloca(arg.getType(), 0, arg.getName()+".addr");

        // Store the initial value into the alloca.
        builder.CreateStore(&arg, alloca);

        // Add arguments to variable symbol table.
        current_block->named_values[arg.getName()] = Variable(arg.getName(), arg.getType(), alloca);
    }

    // Make body
    ctx->block()->accept(this);

    // Verify
    verifyFunction(*function);

    return function;
}

/*
 * Signature = parameters [result]
 * Return: nullptr | pair<vector<Variable>, Type*> - arguments and return type
 */
Any Go2LLVMMyVisitor::visitSignature(Go2LLVMParser::SignatureContext *ctx) {
    parser_errors.Log("visitSignature");

    vector<Variable> parameters;
    Type* result;

    Any any_v = ctx->parameters()->accept(this); if(any_v.isNull()) return nullptr;
    parameters = any_v.as<vector<Variable>>();

    if(ctx->result() != nullptr) {
        any_v = ctx->result()->accept(this);
        if(any_v.isNull())
            return nullptr;
        result = any_v;
    } else {
        result = Variable::TypeFromStr(context, "void");
    }

    pair<vector<Variable>, Type*> signature = std::make_pair(parameters, result);
    return signature;
}

/*
 * Result = parameters | type
 * Return: nullptr | Type* - type
 */
Any Go2LLVMMyVisitor::visitResult(Go2LLVMParser::ResultContext *ctx) {
    parser_errors.Log("visitResult");

    if(ctx->type() != nullptr) {
        return ctx->type()->accept(this);
    } else {
        // todo: handle list of params in result
        return Variable::TypeFromStr(context, "void");
    }
}

/*
 * Parameters = '(' [parameterList [',']] ')'
 * Return: nullptr | vector<Variable> - parameters
 */
Any Go2LLVMMyVisitor::visitParameters(Go2LLVMParser::ParametersContext *ctx) {
    parser_errors.Log("visitParameters");

    vector<Variable> parameters;
    if(ctx->parameterList() != nullptr) {
        Any any_v = ctx->parameterList()->accept(this); if(any_v.isNull()) return nullptr;
        parameters = any_v.as<vector<Variable>>();
    }
    return parameters;
}

/*
 * ParameterList = parameterDecl { COMMA parameterDecl }
 * Return: nullptr | vector<Variable> - parameters
 */
Any Go2LLVMMyVisitor::visitParameterList(Go2LLVMParser::ParameterListContext *ctx) {
    parser_errors.Log("visitParameterList");

    vector<Variable> identifiers;
    for(auto parameterDecl : ctx->parameterDecl()) {
        Any any_v = parameterDecl->accept(this); if(any_v.isNull()) return nullptr;

        vector<Variable> identifiers_to_append = any_v;
        identifiers.insert(identifiers.end(), identifiers_to_append.begin(), identifiers_to_append.end());
    }
    return identifiers;
}

/*
 * ParameterDecl = identifielList type
 * Return: nullptr | vector<Variable> - parameters
 */
Any Go2LLVMMyVisitor::visitParameterDecl(Go2LLVMParser::ParameterDeclContext *ctx) {
    vector<string> identifiers = ctx->identifierList()->accept(this);

    Any any_v = ctx->type()->accept(this); if(any_v.isNull()) return nullptr;
    Type *type = any_v;

    vector<Variable> parameters;
    for(auto identifier : identifiers) {
        parameters.push_back(Variable(identifier, type));
    }
    return parameters;
}

