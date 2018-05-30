#include "Go2LLVMMyVisitor.h"

using namespace go_parser;
using namespace llvm;
using antlrcpp::Any;
using std::string;
using std::vector;
using std::pair;


/*
 * StatementList = { Statement EOS }
 * Return:
 */
Any Go2LLVMMyVisitor::visitStatementList(Go2LLVMParser::StatementListContext *ctx) {
    parser_errors.Log("visitStatementList: " + ctx->getText());
    for(auto statement : ctx->statement()) {
        statement->accept(this);
    }
    builder.Insert
}

/*
 * Statement = Declaration | SimpleStmt | Block | ReturnStmt | IfStmt
 * Return: nullptr | Value*
 */
Any Go2LLVMMyVisitor::visitStatement(Go2LLVMParser::StatementContext *ctx) {
    parser_errors.Log("visitStatement: " + ctx->getText());

    if(ctx->declaration() != nullptr) {
        ctx->declaration()->accept(this);

    } else if(ctx->simpleStmt() != nullptr) {
        Any any_v = ctx->simpleStmt()->accept(this); if(any_v.isNull()) return nullptr;
        return any_v.as<Value*>();

    } else if(ctx->block() != nullptr) {
        ctx->block()->accept(this);

    } else if(ctx->returnStmt() != nullptr) {
        ctx->returnStmt()->accept(this);
    }

    return nullptr;
}

Any Go2LLVMMyVisitor::visitIfStmt(Go2LLVMParser::IfStmtContext *ctx) {
    return visitChildren(ctx);
}

/*
 * ReturnStmt = "return" [ExpressionList]
 * Return: nullptr | vector<Value*>
 */
Any Go2LLVMMyVisitor::visitReturnStmt(Go2LLVMParser::ReturnStmtContext *ctx) {
    parser_errors.Log("visitReturnStmt: " + ctx->getText());
    if(ctx->expressionList() != nullptr) {
        Any any_v = ctx->expressionList()->accept(this); if(any_v.isNull()) return nullptr;
        return any_v.as<vector<Value*>>();
    }
    return nullptr;
}

/*
 * SimpleStmt = EmptyStmt | Expression | Assignment
 * Return: nullptr | Value*
 */
Any Go2LLVMMyVisitor::visitSimpleStmt(Go2LLVMParser::SimpleStmtContext *ctx) {
    parser_errors.Log("visitSimpleStmt: " + ctx->getText());

    if(ctx->emptyStmt() != nullptr) {
        return nullptr;

    } else if(ctx->expression() != nullptr) {
        return ctx->expression()->accept(this);

    } else if(ctx->assignment() != nullptr) {
        return ctx->assignment()->accept(this);
    }

    return nullptr;
}

/*
 * Assignment = identifierList [add_op | mul_op] '=' expressionList
 * Return: nullptr
 */
Any Go2LLVMMyVisitor::visitAssignment(Go2LLVMParser::AssignmentContext *ctx) {
    parser_errors.Log("visitAssignment: " + ctx->getText());

    vector<string> identifiers = ctx->identifierList()->accept(this);

    Any any_v = ctx->expressionList()->accept(this); if(any_v.isNull()) return nullptr;
    vector<Value*> assignments = any_v;

    if(identifiers.size() != assignments.size())
        return parser_errors.AddError(ctx->getStart()->getLine(), "identifiers list size != right hand side size");

    return nullptr;
}

/*
 * EmptyStmt = ";"
 * Return: nullptr
 */
Any Go2LLVMMyVisitor::visitEmptyStmt(Go2LLVMParser::EmptyStmtContext *ctx) {
    return nullptr;
}