#include "Go2LLVMMyVisitor.h"
#include "../variables/IntegerVar.h"
#include "../variables/FloatVar.h"

using namespace go_parser;
using namespace llvm;
using antlrcpp::Any;
using std::string;
using std::vector;
using std::pair;


/*
 * OperandBasicList = basicLit
 * Return: BasicVar*
 */
Any Go2LLVMMyVisitor::visitOperandBasicLit(Go2LLVMParser::OperandBasicLitContext *ctx) {
    Go2LLVMError::Log("visitOperandBasicLit: " + ctx->getText());
    return ctx->basicLit()->accept(this).as<BasicVar *>();
}

/*
 * BasicLit = int_tok | float_tok | imag_tok  | string_tok
 * Return: BasicVar*
 */
Any Go2LLVMMyVisitor::visitBasicLit(Go2LLVMParser::BasicLitContext *ctx) {
    Go2LLVMError::line_no = ctx->getStart()->getLine();
    Go2LLVMError::Log("visitBasicLit: " + ctx->getText());

    if (ctx->INT_TOK() != nullptr) {
        return (BasicVar *) var_factory.Get("IntegerVar", ctx->getText());
    } else if (ctx->FLOAT_TOK() != nullptr) {
        return (BasicVar *) var_factory.Get("FloatVar", ctx->getText());
    } else if (ctx->IMAG_TOK() != nullptr) {
        throw Go2LLVMError("Imaginary numbers not supported: " + ctx->getText());
    } else if (ctx->STRING_TOK() != nullptr) {
        string unescaped = StringHelper::Unescape(ctx->getText());
        Value *str = builder.CreateGlobalStringPtr(unescaped, "global_str");
        return (BasicVar *) var_factory.Get("global_str", str->getType(), str);
    } else if (ctx->BOOL_TOK() != nullptr) {
        return (BasicVar *) var_factory.Get("BoolVar", ctx->getText());
    }

    throw Go2LLVMError("unknown token " + ctx->getText());
}

/*
 * OperandIdent = ident_tok
 * Return: BasicVar*
 */
Any Go2LLVMMyVisitor::visitOperandIdent(Go2LLVMParser::OperandIdentContext *ctx) {
    Go2LLVMError::line_no = ctx->getStart()->getLine();
    Go2LLVMError::Log("visitOperandIdent: " + ctx->getText());

    string name = ctx->IDENT_TOK()->getText();
    try {
        BasicVar *variable_ptr_value = current_block->GetNamedValue(name);
        Type *raw_type = ((PointerType *) variable_ptr_value->getType())->getElementType();
        LoadInst *load = builder.CreateLoad(variable_ptr_value->getValue(), name.c_str());
        return var_factory.Get(variable_ptr_value->name, load->getType(), load);
    } catch (NoNamedValueException) {
        throw Go2LLVMError("unknown variable name " + name);
    }
}

/*
 * OperandFunc = ident_tok Arguments, this is function call
 * Return: BasicVar*
 */
Any Go2LLVMMyVisitor::visitOperandFunc(Go2LLVMParser::OperandFuncContext *ctx) {
    Go2LLVMError::line_no = ctx->getStart()->getLine();
    Go2LLVMError::Log("visitOperandFunc: " + ctx->getText());

    // Function name
    string function_name = ctx->IDENT_TOK()->getText();

    // Get arguments
    vector<BasicVar *> arguments = ctx->arguments()->accept(this);

    // Find function
    Function *callee_function = module->getFunction(function_name);
    if (!callee_function)
        throw Go2LLVMError("Unknown function referenced: " + function_name);

    // If argument mismatch error.
    if (!callee_function->isVarArg() && callee_function->arg_size() != arguments.size())
        throw Go2LLVMError("Incorrect number of arguments passed to " + function_name);

    // Casts
    vector<Value *> arguments_casted;
    arguments_casted.reserve(arguments.size());
    Value *call;

    if (!callee_function->isVarArg()) {
        size_t i = 0;
        for (auto &arg : callee_function->args()) {
            arguments_casted.push_back(
                    var_factory.Get("argVar", arg.getType(), arguments.at(i)->getValue())->getValue());
            i++;
        }
    } else {
        for (auto &arg : arguments) {
            arguments_casted.push_back(arg->getValue());
        }
    }


    if (callee_function->getReturnType()->isVoidTy())
        call = builder.CreateCall(callee_function, arguments_casted);
    else
        call = builder.CreateCall(callee_function, arguments_casted, "call_" + function_name);
    return var_factory.Get(call->getName(), call->getType(), call);
}

/*
 * Arguments = '(' [ExpressionList [',']] ')'
 * Return: vector<BasicVar*>
 */
Any Go2LLVMMyVisitor::visitArguments(Go2LLVMParser::ArgumentsContext *ctx) {
    Go2LLVMError::line_no = ctx->getStart()->getLine();
    Go2LLVMError::Log("visitArguments: " + ctx->getText());

    vector<BasicVar *> arguments;
    if (ctx->expressionList() != nullptr) {
        arguments = ctx->expressionList()->accept(this).as<vector<BasicVar *>>();
    }

    return arguments;
}

/*
 * OperandExp = PO expression PC
 * Return: BasicVar*
 */
Any Go2LLVMMyVisitor::visitOperandExp(Go2LLVMParser::OperandExpContext *ctx) {
    return ctx->expression()->accept(this).as<BasicVar *>();
}
