#include "Go2LLVMMyVisitor.h"

using namespace go_parser;
using namespace llvm;
using antlrcpp::Any;
using std::string;
using std::vector;
using std::pair;


/*
 * OperandBasicList = basicLit
 * Return: nullptr | Value*
 */
Any Go2LLVMMyVisitor::visitOperandBasicLit(Go2LLVMParser::OperandBasicLitContext *ctx) {
    parser_errors.Log("visitOperandBasicLit: " + ctx->getText());
    Any any_v = ctx->basicLit()->accept(this); if(any_v.isNull()) return nullptr;
    return any_v;
}

Any Go2LLVMMyVisitor::visitOperandIdent(Go2LLVMParser::OperandIdentContext *ctx) {
    parser_errors.Log("visitOperandIdent: " + ctx->getText());
    return visitChildren(ctx);
}

/*
 * OperandFunc = ident_tok Arguments, this is function call
 * Return: nullptr | Value*
 */
Any Go2LLVMMyVisitor::visitOperandFunc(Go2LLVMParser::OperandFuncContext *ctx) {
    parser_errors.Log("visitOperandFunc: " + ctx->getText());

    // Function name
    string function_name = ctx->IDENT_TOK()->getText();

    // Get arguments
    Any any_v = ctx->arguments()->accept(this); if(any_v.isNull()) return nullptr;
    vector<Value*> arguments = any_v;

    // Find function
    Function *callee_function = the_module->getFunction(function_name);
    if (!callee_function)
        return parser_errors.AddError(ctx->getStart()->getLine(), "Unknown function referenced");

    // If argument mismatch error.
    if (callee_function->arg_size() != arguments.size())
        return parser_errors.AddError(ctx->getStart()->getLine(), "Incorrect # arguments passed");

    return builder.CreateCall(callee_function, arguments, "call_" + function_name);
}

Any Go2LLVMMyVisitor::visitOperandExp(Go2LLVMParser::OperandExpContext *ctx) {
    return visitChildren(ctx);
}

/*
 * Arguments '(' [ExpressionList [',']] ')'
 * Return: nullptr | vector<Value*>
 */
Any Go2LLVMMyVisitor::visitArguments(Go2LLVMParser::ArgumentsContext *ctx) {
    parser_errors.Log("visitArguments: " + ctx->getText());

    if(ctx->expressionList() != nullptr) {
        Any any_v = ctx->expressionList()->accept(this);
        if(any_v.isNull())
            return nullptr;
        return any_v.as<vector<Value*>>();
    }

    return nullptr;
}

/*
 * BasicLit = int_tok | float_tok | imag_tok  | string_tok
 * Return: nullptr | Value*
 */
Any Go2LLVMMyVisitor::visitBasicLit(Go2LLVMParser::BasicLitContext *ctx) {
    parser_errors.Log("visitBasicLit: " + ctx->getText());
    if(ctx->INT_TOK() != nullptr) {
        return (Value*)ConstantInt::get(*the_context, APInt(32, ctx->getText(), 10));
    } else if(ctx->FLOAT_TOK() != nullptr) {
        return (Value*)ConstantFP::get(*the_context, APFloat(APFloat::IEEEquad, ctx->getText()));
    } else if(ctx->IMAG_TOK() != nullptr) {
        return (Value*)ConstantFP::get(*the_context, APFloat(APFloat::IEEEquad, ctx->getText()));
    } else if(ctx->STRING_TOK() != nullptr) {
        return nullptr;
    }

    return parser_errors.AddError(ctx->getStart()->getLine(), "unknown token " + ctx->getText());
}
