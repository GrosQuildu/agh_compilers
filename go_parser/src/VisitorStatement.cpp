#include "Go2LLVMMyVisitor.h"
#include <vector>

using namespace go_parser;
using namespace llvm;
using antlrcpp::Any;
using std::string;
using std::vector;
using std::pair;


/*
 * StatementList = { Statement EOS }
 * Return: nullptr
 */
Any Go2LLVMMyVisitor::visitStatementList(Go2LLVMParser::StatementListContext *ctx) {
    parser_errors.Log("visitStatementList: " + ctx->getText());
    for(auto statement : ctx->statement()) {
        statement->accept(this);
    }
    return nullptr;
}

/*
 * Statement = Declaration | SimpleStmt | Block | ReturnStmt | IfStmt
 * Return: nullptr
 */
Any Go2LLVMMyVisitor::visitStatement(Go2LLVMParser::StatementContext *ctx) {
    parser_errors.Log("visitStatement: " + ctx->getText());

    if(ctx->declaration() != nullptr) {
        Any any_v = ctx->declaration()->accept(this); if(any_v.isNull()) return nullptr;
        for (auto &variable : any_v.as<vector<Variable>>()) {

            try {
                current_block->get_named_value(variable.name);
                parser_errors.AddError(ctx->getStart()->getLine(), "variable " + variable.name + " is already defined");
                continue;
            } catch(NoNamedValueException) {

            }

            // Create an alloca for the variable
            AllocaInst *alloca = builder.CreateAlloca(builder.getInt32Ty(), 0,variable.name+".addr");

            // Store the initial value into the alloca.
            if(variable.value != nullptr)
                builder.CreateStore(variable.value, alloca);

            // Add variable to block's symbol table.
            current_block->named_values[variable.name] = Variable(variable.name, "int32", alloca);
        }

    } else if(ctx->simpleStmt() != nullptr) {
        ctx->simpleStmt()->accept(this);

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
 * Return: nullptr
 */
Any Go2LLVMMyVisitor::visitReturnStmt(Go2LLVMParser::ReturnStmtContext *ctx) {
    parser_errors.Log("visitReturnStmt: " + ctx->getText());

    if(ctx->expressionList() != nullptr) {
        Any any_v = ctx->expressionList()->accept(this); if(any_v.isNull()) return nullptr;
        vector<Value*> expressions = any_v;

        // for now one value is returned
        for(auto expression : expressions) {
            builder.CreateRet(expression);
            break;
        }
    } else {
        builder.CreateRetVoid();
    }

    return nullptr;
}

/*
 * SimpleStmt = EmptyStmt | Expression | Assignment
 * Return: nullptr
 */
Any Go2LLVMMyVisitor::visitSimpleStmt(Go2LLVMParser::SimpleStmtContext *ctx) {
    parser_errors.Log("visitSimpleStmt: " + ctx->getText());

    if(ctx->emptyStmt() != nullptr) {
        return nullptr;

    } else if(ctx->expression() != nullptr) {
        ctx->expression()->accept(this);

    } else if(ctx->assignment() != nullptr) {
        ctx->assignment()->accept(this);
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

    for(size_t i = 0; i<identifiers.size(); i++) {
        try {
            Value *v = current_block->get_named_value(identifiers.at(i)).value;
            builder.CreateStore(assignments.at(i), v);
        } catch(NoNamedValueException) {
            return parser_errors.AddError(ctx->getStart()->getLine(), "unknown variable name " + identifiers.at(i));
        }
    }

    return nullptr;
}

/*
 * EmptyStmt = ";"
 * Return: nullptr
 */
Any Go2LLVMMyVisitor::visitEmptyStmt(Go2LLVMParser::EmptyStmtContext *ctx) {
    return nullptr;
}