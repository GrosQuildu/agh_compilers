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
    Go2LLVMError::Log("visitOperandBasicLit: " + ctx->getText());
    return ctx->basicLit()->accept(this).as<Value*>();
}

/*
 * BasicLit = int_tok | float_tok | imag_tok  | string_tok
 * Return: nullptr | Value*
 */
Any Go2LLVMMyVisitor::visitBasicLit(Go2LLVMParser::BasicLitContext *ctx) {
    Go2LLVMError::Log("visitBasicLit: " + ctx->getText());
    if(ctx->INT_TOK() != nullptr) {

        string number = ctx->getText();
        // minimal amount of bits required to store this literal
        size_t bit_width;

        if(number.substr(0, 2) == "0x" || number.substr(0, 2) == "0X") {
            number = number.substr(2);
            bit_width = 1 + number.length()*4;
            return (Value*)ConstantInt::get(context, APInt(bit_width, number, 16));
        } else if(number.substr(0, 1) == "0") {
            number = number.substr(1);
            bit_width = 1 + number.length()*3;
            return (Value*)ConstantInt::get(context, APInt(bit_width, number, 8));
        } else {
            bit_width = 2 + 3*number.length() + ((number.length()-1)/3);
            return (Value*)ConstantInt::get(context, APInt(bit_width, number, 10));
        }

    } else if(ctx->FLOAT_TOK() != nullptr) {
        return (Value*)ConstantFP::get(context, APFloat(APFloat::IEEEquad, ctx->getText()));
    } else if(ctx->IMAG_TOK() != nullptr) {
        throw Go2LLVMError(ctx->getStart()->getLine(), "Imaginary numbers not supported: " + ctx->getText());
        // return (Value*)ConstantFP::get(context, APFloat(APFloat::IEEEquad, ctx->getText()));
    } else if(ctx->STRING_TOK() != nullptr) {
        StringRef unescaped = StringHelper::Unescape(ctx->getText());
        return (Value*)builder.CreateGlobalStringPtr(unescaped, "global_str");
    }

    throw Go2LLVMError(ctx->getStart()->getLine(), "unknown token " + ctx->getText());
}

/*
 * OperandIdent = ident_tok
 * Return: nullptr | Value*
 */
Any Go2LLVMMyVisitor::visitOperandIdent(Go2LLVMParser::OperandIdentContext *ctx) {
    Go2LLVMError::Log("visitOperandIdent: " + ctx->getText());

    string name = ctx->IDENT_TOK()->getText();
    try {
        Value *v = current_block->GetNamedValue(name).value;
        return (Value*)builder.CreateLoad(v, name.c_str());
    } catch(NoNamedValueException) {
        throw Go2LLVMError(ctx->getStart()->getLine(), "unknown variable name " + name);
    }
}

/*
 * OperandFunc = ident_tok Arguments, this is function call
 * Return: nullptr | Value*
 */
Any Go2LLVMMyVisitor::visitOperandFunc(Go2LLVMParser::OperandFuncContext *ctx) {
    Go2LLVMError::Log("visitOperandFunc: " + ctx->getText());

    // Function name
    string function_name = ctx->IDENT_TOK()->getText();

    // Get arguments
    vector<Value*> arguments = ctx->arguments()->accept(this);

    // Find function
    Function *callee_function = module->getFunction(function_name);
    if (!callee_function)
        throw Go2LLVMError(ctx->getStart()->getLine(), "Unknown function referenced: " + function_name);

    // If argument mismatch error.
    if (!callee_function->isVarArg() && callee_function->arg_size() != arguments.size())
        throw Go2LLVMError(ctx->getStart()->getLine(), "Incorrect number of arguments passed to " + function_name);

    // Casts
    if(!callee_function->isVarArg()) {
        size_t i = 0;
        vector<Value *> arguments_casted;
        arguments_casted.reserve(arguments.size());
        for (auto &arg : callee_function->args()) {
            arguments_casted.push_back(
                    Variable::CastL2R(ctx->getStart()->getLine(), builder, arguments.at(i), arg.getType()));
            i++;
        }
        return (Value*)builder.CreateCall(callee_function, arguments_casted, "call_" + function_name);
    } else {
        return (Value*)builder.CreateCall(callee_function, arguments, "call_" + function_name);
    }
}

/*
 * Arguments = '(' [ExpressionList [',']] ')'
 * Return: nullptr | vector<Value*>
 */
Any Go2LLVMMyVisitor::visitArguments(Go2LLVMParser::ArgumentsContext *ctx) {
    Go2LLVMError::Log("visitArguments: " + ctx->getText());

    vector<Value*> arguments;
    if(ctx->expressionList() != nullptr) {
        arguments = ctx->expressionList()->accept(this).as<vector<Value*>>();
    }

    return arguments;
}

/*
 * OperandExp = PO expression PC
 * Return: nullptr | Value*
 */
Any Go2LLVMMyVisitor::visitOperandExp(Go2LLVMParser::OperandExpContext *ctx) {
    return ctx->expression()->accept(this).as<Value*>();
}
