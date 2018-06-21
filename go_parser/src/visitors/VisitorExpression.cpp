#include "Go2LLVMMyVisitor.h"

using namespace go_parser;
using namespace llvm;
using antlrcpp::Any;
using std::string;
using std::vector;
using std::pair;

/*
 * Expression = UnaryExpr | Expression binary_op_tok Expression
 * Return: BasicVar*
 */
Any Go2LLVMMyVisitor::visitExpression(Go2LLVMParser::ExpressionContext *ctx) {
    Go2LLVMError::line_no = ctx->getStart()->getLine();
    Go2LLVMError::Log("visitExpression: " + ctx->getText());

    if(ctx->unaryExpr() != nullptr) {
        // UnaryExpr
        return ctx->unaryExpr()->accept(this).as<BasicVar*>();

    } else if(ctx->LE != nullptr && ctx->RE != nullptr && ctx->binary_op_tok != nullptr){
        // Expression binary_op_tok Expression
        string binaryOperator = ctx->binary_op_tok->getText();

        BasicVar *l = ctx->LE->accept(this);
        BasicVar *r = ctx->RE->accept(this);
        std::tie(l, r) = var_factory.BestCast(l, r);
        return l->CreateExpression(binaryOperator, r);
    }

    throw Go2LLVMError("unknown token " + ctx->getText());
}

/*
 * UnaryExpr = unary_op_tok UnaryExpr | operand
 * Return: BasicVar*
 */
Any Go2LLVMMyVisitor::visitUnaryExpr(Go2LLVMParser::UnaryExprContext *ctx) {
    Go2LLVMError::line_no = ctx->getStart()->getLine();
    Go2LLVMError::Log("visitUnaryExpr: " + ctx->getText());

    if(ctx->operand() != nullptr) {
        // operand
        return ctx->operand()->accept(this).as<BasicVar*>();

    } else if(ctx->unary_op_tok != nullptr) {
        // unary_op_tok UnaryExpr
        string unaryOperator = ctx->unary_op_tok->getText().c_str();

        BasicVar *r = ctx->unaryExpr()->accept(this);
        return r->Expression(unaryOperator);
    }

    throw Go2LLVMError("unknown token " + ctx->getText());
}

/*
 * ExpressionList = Expression { "," Expression }
 * Return: vector<BasicVar*>
 */
Any Go2LLVMMyVisitor::visitExpressionList(Go2LLVMParser::ExpressionListContext *ctx) {
    Go2LLVMError::line_no = ctx->getStart()->getLine();
    Go2LLVMError::Log("visitExpressionList: " + ctx->getText());

    vector<BasicVar *> expressions;
    for(auto expression : ctx->expression()) {
        BasicVar *v = expression->accept(this);
        expressions.push_back(v);
    }
    return expressions;
}
