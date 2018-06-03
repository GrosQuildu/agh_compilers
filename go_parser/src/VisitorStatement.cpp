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
    Go2LLVMError::Log("visitStatementList: " + ctx->getText());
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
    Go2LLVMError::Log("visitStatement: " + ctx->getText());

    if(ctx->declaration() != nullptr) {
        vector<Variable> variables = ctx->declaration()->accept(this);
        for (auto &variable : variables) {

            try {
                current_block->get_named_value(variable.name);
                throw Go2LLVMError(ctx->getStart()->getLine(), "variable " + variable.name + " is already defined");
            } catch(NoNamedValueException) {}

            // Create an alloca for the variable
            AllocaInst *alloca = builder.CreateAlloca(variable.type, 0, variable.name+".addr");

            // Store the initial value into the alloca.
            if(variable.value != nullptr)
                builder.CreateStore(variable.value, alloca);

            // Add variable to block's symbol table.
            current_block->named_values[variable.name] = Variable(variable.name, variable.type, alloca);
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
    Go2LLVMError::Log("visitReturnStmt: " + ctx->getText());

    if(ctx->expressionList() != nullptr) {
        vector<Value*> expressions = ctx->expressionList()->accept(this);

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
    Go2LLVMError::Log("visitSimpleStmt: " + ctx->getText());

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
    Go2LLVMError::Log("visitAssignment: " + ctx->getText());

    vector<string> identifiers = ctx->identifierList()->accept(this);
    vector<Value*> assignments = ctx->expressionList()->accept(this);

    if(identifiers.size() != assignments.size())
        throw Go2LLVMError(ctx->getStart()->getLine(), "identifiers list size != right hand side size");

    for(size_t i = 0; i<identifiers.size(); i++) {
        try {
            Value *v = current_block->get_named_value(identifiers.at(i)).value;
            builder.CreateStore(assignments.at(i), v);
        } catch(NoNamedValueException) {
            throw Go2LLVMError(ctx->getStart()->getLine(), "unknown variable name " + identifiers.at(i));
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