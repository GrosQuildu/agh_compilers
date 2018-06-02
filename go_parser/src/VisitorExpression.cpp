#include "Go2LLVMMyVisitor.h"

using namespace go_parser;
using namespace llvm;
using antlrcpp::Any;
using std::string;
using std::vector;
using std::pair;

/*
 * Expression = UnaryExpr | Expression binary_op_tok Expression
 * Return: nullptr | Value*
 */
Any Go2LLVMMyVisitor::visitExpression(Go2LLVMParser::ExpressionContext *ctx) {
    parser_errors.Log("visitExpression: " + ctx->getText());

    if(ctx->unaryExpr() != nullptr) {
        // UnaryExpr
        Any any_v = ctx->unaryExpr()->accept(this); if(any_v.isNull()) return nullptr;
        Value* v = any_v;
        return v;

    } else if(ctx->LE != nullptr && ctx->RE != nullptr && ctx->binary_op_tok != nullptr){
        // Expression binary_op_tok Expression
        Any any_l = ctx->LE->accept(this); if(any_l.isNull()) return nullptr;
        Value* l = any_l;

        Any any_r = ctx->LE->accept(this); if(any_r.isNull()) return nullptr;
        Value* r = any_r;

        char binaryOperator = ctx->binary_op_tok->getText()[0];
        switch(binaryOperator) {
            case '+': return builder.CreateAdd(l, r, "binaryAdd");
            case '-': return builder.CreateSub(l, r, "binarySub");
            case '*': return builder.CreateMul(l, r, "binaryDiv");
            case '/': return builder.CreateSDiv(l, r, "binaryMul");
            default: return parser_errors.AddError(ctx->getStart()->getLine(),
                                                  "unknown unary operator " + binaryOperator);
        }
    }

    return parser_errors.AddError(ctx->getStart()->getLine(), "unknown token " + ctx->getText());
}

/*
 * UnaryExpr = unary_op_tok UnaryExpr | operand
 * Return: nullptr | Value*
 */
Any Go2LLVMMyVisitor::visitUnaryExpr(Go2LLVMParser::UnaryExprContext *ctx) {
    parser_errors.Log("visitUnaryExpr: " + ctx->getText());

    if(ctx->operand() != nullptr) {
        // operand
        Any any_v = ctx->operand()->accept(this); if(any_v.isNull()) return nullptr;
        return any_v.as<Value*>();

    } else if(ctx->unary_op_tok != nullptr) {
        // unary_op_tok UnaryExpr
        Any any_r = ctx->unaryExpr()->accept(this); if(any_r.isNull()) return nullptr;
        Value* r = any_r;

        char unaryOperator = ctx->unary_op_tok->getText().c_str()[0];
        switch (unaryOperator) {
            case '+': return r;
            case '-': return builder.CreateSub(ConstantInt::get(context, APInt(32, 0)), r, "unarySub");
            default: return parser_errors.AddError(ctx->getStart()->getLine(), "unknown unary operator " + unaryOperator);
        }
    }

    return parser_errors.AddError(ctx->getStart()->getLine(), "unknown token " + ctx->getText());
}

/*
 * ExpressionList = Expression { "," Expression }
 * Return: nullptr | vector<Value*>
 */
Any Go2LLVMMyVisitor::visitExpressionList(Go2LLVMParser::ExpressionListContext *ctx) {
    parser_errors.Log("visitExpressionList: " + ctx->getText());

    vector<Value *> expressions;
    for(auto expression : ctx->expression()) {
        Any any_v = expression->accept(this); if(any_v.isNull()) return nullptr;
        Value* V = any_v;
        expressions.push_back(V);
    }
    return expressions;
}
