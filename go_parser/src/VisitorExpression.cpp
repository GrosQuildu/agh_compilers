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
    Go2LLVMError::Log("visitExpression: " + ctx->getText());

    if(ctx->unaryExpr() != nullptr) {
        // UnaryExpr
        Value *v = ctx->unaryExpr()->accept(this);
        return v;

    } else if(ctx->LE != nullptr && ctx->RE != nullptr && ctx->binary_op_tok != nullptr){
        // Expression binary_op_tok Expression
        Value *l = ctx->LE->accept(this);
        Value *r = ctx->RE->accept(this);

        std::tie(l, r) = Variable::Cast(ctx->getStart()->getLine(), builder, l, r);

        char binaryOperator = ctx->binary_op_tok->getText()[0];
        if(l->getType()->isFloatingPointTy() && r->getType()->isFloatingPointTy()) {
            switch(binaryOperator) {
                case '+': return builder.CreateFAdd(l, r, "binaryFAdd");
                case '-': return builder.CreateFSub(l, r, "binaryFSub");
                case '*': return builder.CreateFMul(l, r, "binaryFMul");
                case '/': return builder.CreateFDiv(l, r, "binaryFDiv");
                case '=': return builder.CreateFCmp(CmpInst::Predicate::FCMP_OEQ, l, r, "binaryFCmp");
                default: throw Go2LLVMError(ctx->getStart()->getLine(),
                                            "unknown unary operator " + binaryOperator);
            }
        } else if(l->getType()->isIntegerTy() && r->getType()->isIntegerTy()) {
            switch(binaryOperator) {
                case '+': return builder.CreateAdd(l, r, "binaryAdd");
                case '-': return builder.CreateSub(l, r, "binarySub");
                case '*': return builder.CreateMul(l, r, "binaryMul");
                case '/': return builder.CreateSDiv(l, r, "binaryDiv");
                case '=': return builder.CreateICmp(CmpInst::Predicate::ICMP_EQ, l, r, "binaryCmp");
                default: throw Go2LLVMError(ctx->getStart()->getLine(),
                                            "unknown unary operator " + binaryOperator);
            }
        } else {
            throw Go2LLVMError(ctx->getStart()->getLine(),
                               "types mismatch for " + binaryOperator);
        }
    }

    throw Go2LLVMError(ctx->getStart()->getLine(), "unknown token " + ctx->getText());
}

/*
 * UnaryExpr = unary_op_tok UnaryExpr | operand
 * Return: nullptr | Value*
 */
Any Go2LLVMMyVisitor::visitUnaryExpr(Go2LLVMParser::UnaryExprContext *ctx) {
    Go2LLVMError::Log("visitUnaryExpr: " + ctx->getText());

    if(ctx->operand() != nullptr) {
        // operand
        return ctx->operand()->accept(this).as<Value*>();

    } else if(ctx->unary_op_tok != nullptr) {
        // unary_op_tok UnaryExpr
        Value *r = ctx->unaryExpr()->accept(this);

        char unaryOperator = ctx->unary_op_tok->getText().c_str()[0];
        switch (unaryOperator) {
            case '+': return r;
            case '-':
                if(r->getType()->isFloatingPointTy())
                    return builder.CreateSub(ConstantFP::getZeroValueForNegation(r->getType()), r, "unarySub");
                else if(r->getType()->isIntegerTy())
                    return builder.CreateSub(ConstantInt::get(context, APInt(r->getType()->getIntegerBitWidth(), 0)), r, "unarySub");
            default: throw Go2LLVMError(ctx->getStart()->getLine(), "unknown unary operator " + unaryOperator);
        }
    }

    throw Go2LLVMError(ctx->getStart()->getLine(), "unknown token " + ctx->getText());
}

/*
 * ExpressionList = Expression { "," Expression }
 * Return: nullptr | vector<Value*>
 */
Any Go2LLVMMyVisitor::visitExpressionList(Go2LLVMParser::ExpressionListContext *ctx) {
    Go2LLVMError::Log("visitExpressionList: " + ctx->getText());

    vector<Value *> expressions;
    for(auto expression : ctx->expression()) {
        Value *v = expression->accept(this);
        expressions.push_back(v);
    }
    return expressions;
}
