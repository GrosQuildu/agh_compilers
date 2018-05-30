#include "Go2LLVMMyVisitor.h"

using namespace go_parser;
using namespace llvm;
using antlrcpp::Any;
using std::string;
using std::vector;
using std::pair;

/*
 * Function = func_tok ident_tok signature block
 * Return: nullptr | Function*
 */
Any Go2LLVMMyVisitor::visitFunctionDecl(Go2LLVMParser::FunctionDeclContext *ctx) {
    parser_errors.Log("visitFunctionDecl");

    // Function name
    string function_name = ctx->IDENT_TOK()->getText();

    Function *function = the_module->getFunction(function_name);
    if(function) {
        return parser_errors.AddError(ctx->getStart()->getLine(), "Function " + function_name + " already defined");
    }

    // Function signature - parameters and return types/variables
    pair<vector<string>, string> signature = ctx->signature()->accept(this);
    vector<string> arguments = signature.first;
    string return_type = signature.second;

    // Make the function type
    vector<Type*> argsTypes(arguments.size(), Type::getInt32Ty(*the_context));
    FunctionType *function_type = FunctionType::get(Type::getInt32Ty(*the_context), argsTypes, false);

    // Create function
    function = Function::Create(function_type, Function::ExternalLinkage, function_name, the_module);

    // Set arg names
    unsigned i = 0;
    for (auto &arg : function->args())
        arg.setName(arguments.at(i++));

    // Create a new basic block to start insertion into.
    BasicBlock *bb = BasicBlock::Create(*the_context, "entry", function);
    builder.SetInsertPoint(bb);

    // Record the function arguments in the NamedValues map.
    for (auto &arg : function->args())
        named_values[arg.getName()] = &arg;

    // Make body
    if(ctx->block() != nullptr) {
        Any any_ret_val = ctx->block()->accept(this);
        if (any_ret_val.isNull()) {
            function->eraseFromParent();
            return nullptr;
        }
        Value *ret_val = any_ret_val.as<Value *>();
        builder.CreateRet(ret_val);
    }

    // Verify
    verifyFunction(*function);

    return function;
}

/*
 * Signature = parameters [result]
 * Return: pair<vector<string>, string> - identifiers (arguments) and return type
 */
Any Go2LLVMMyVisitor::visitSignature(Go2LLVMParser::SignatureContext *ctx) {
    parser_errors.Log("visitSignature");

    vector<string> parameters;
    string result;

    Any any_v = ctx->parameters()->accept(this);
    if(any_v.isNotNull()){
        parameters = any_v.as<vector<string>>();
    }

    if(ctx->result() != nullptr) {
        any_v = ctx->result()->accept(this);
        if(any_v.isNotNull())
            result = any_v.as<string>();
    }

    pair<vector<string>, string> signature = std::make_pair(parameters, result);
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
        // handle list of params in result
        return nullptr;
    }
}

/*
 * Parameters = '(' [parameterList [',']] ')'
 * Return: nullptr | vector<string> - identifiers
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
 * Return: vector<string> - identifiers
 */
Any Go2LLVMMyVisitor::visitParameterList(Go2LLVMParser::ParameterListContext *ctx) {
    parser_errors.Log("visitParameterList");

    vector<string> identifiers;
    for(auto parameterDecl : ctx->parameterDecl()) {
        vector<string> identifiers_to_append = parameterDecl->accept(this);
        identifiers.insert(identifiers.end(), identifiers_to_append.begin(), identifiers_to_append.end());
    }
    return identifiers;
}

/*
 * ParameterDecl = identifielList type
 * Return: vector<string> - identifiers
 */
Any Go2LLVMMyVisitor::visitParameterDecl(Go2LLVMParser::ParameterDeclContext *ctx) {
    vector<string> identifiers = ctx->identifierList()->accept(this);
    string type = ctx->type()->accept(this);
    return identifiers;
}

