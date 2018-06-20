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
    for (auto statement : ctx->statement()) {
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

    if (ctx->declaration() != nullptr) {
        vector<Variable> variables = ctx->declaration()->accept(this);
        for (auto &variable : variables) {

            try {
                current_block->GetNamedValue(module, variable.name);
                throw Go2LLVMError(ctx->getStart()->getLine(), "variable " + variable.name + " is already defined");
            } catch (NoNamedValueException) {}

            // Create an alloca for the variable
            AllocaInst *alloca = builder.CreateAlloca(variable.type, 0, variable.name + ".addr");

            // Store the initial value into the alloca.
            if (variable.value != nullptr) {
                variable.value = Variable::CastL2R(ctx->getStart()->getLine(), builder, variable.value, variable.type);
                builder.CreateStore(variable.value, alloca);
            }

            // Add variable to block's symbol table.
            current_block->named_values[variable.name] = Variable(variable.name, variable.type, alloca);

        }

    } else if (ctx->simpleStmt() != nullptr) {
        ctx->simpleStmt()->accept(this);

    } else if (ctx->block() != nullptr) {
        ctx->block()->accept(this);

    } else if (ctx->returnStmt() != nullptr) {
        ctx->returnStmt()->accept(this);
    } else if (ctx->ifStmt() != nullptr) {
        ctx->ifStmt()->accept(this);
    }

    return nullptr;
}

/*
 * IfStmt = 'if' [SimpleStmt ';'] Expression Block ['else' (IfStmt | Block)]
 * Return: nullptr
 */
Any Go2LLVMMyVisitor::visitIfStmt(Go2LLVMParser::IfStmtContext *ctx) {
    Value *cond_val = ctx->expression()->accept(this);

    Function *function = builder.GetInsertBlock()->getParent();
    BasicBlock *if_bb = BasicBlock::Create(context, "if", function);
    BasicBlock *else_bb = BasicBlock::Create(context, "else");
    BasicBlock *merge_bb = BasicBlock::Create(context, "merge");

    if(ctx->ELSE_TOK() != nullptr)
        builder.CreateCondBr(cond_val, if_bb, else_bb);
    else
        builder.CreateCondBr(cond_val, if_bb, merge_bb);

    // Emit if block
    builder.SetInsertPoint(if_bb);
    ctx->block(0)->accept(this);
    builder.CreateBr(merge_bb);
    if_bb = builder.GetInsertBlock();

    if(ctx->ELSE_TOK() != nullptr) {
        // Emit else block
        function->getBasicBlockList().push_back(else_bb);
        builder.SetInsertPoint(else_bb);
        if (ctx->ifStmt() != nullptr)
            ctx->ifStmt()->accept(this);
        else
            ctx->block(1)->accept(this);
        builder.CreateBr(merge_bb);
        else_bb = builder.GetInsertBlock();
    }

    // Emit merge block.
    function->getBasicBlockList().push_back(merge_bb);
    builder.SetInsertPoint(merge_bb);

    return nullptr;
}

/*
 * ReturnStmt = "return" [ExpressionList]
 * Return: nullptr
 */
Any Go2LLVMMyVisitor::visitReturnStmt(Go2LLVMParser::ReturnStmtContext *ctx) {
    Go2LLVMError::Log("visitReturnStmt: " + ctx->getText());

    if (ctx->expressionList() != nullptr) {
        vector<Value *> expressions = ctx->expressionList()->accept(this);

        // for now one value is returned
        for (auto expression : expressions) {
            expression = Variable::CastL2R(ctx->getStart()->getLine(), builder, expression,
                                           builder.getCurrentFunctionReturnType());
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

    if (ctx->emptyStmt() != nullptr) {
        return nullptr;

    } else if (ctx->expression() != nullptr) {
        ctx->expression()->accept(this);

    } else if (ctx->assignment() != nullptr) {
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

    if (identifiers.size() != assignments.size())
        throw Go2LLVMError(ctx->getStart()->getLine(), "identifiers list size != right hand side size");

    for (size_t i = 0; i < identifiers.size(); i++) {
        try {
            Value *variable_ptr_value = current_block->GetNamedValue(module, identifiers.at(i)).value;
            Value *variable_new_value = assignments.at(i);

            variable_new_value = Variable::CastL2R(ctx->getStart()->getLine(), builder, variable_new_value,
                                                   ((PointerType*)variable_ptr_value->getType())->getElementType());
            builder.CreateStore(variable_new_value, variable_ptr_value);
        } catch (NoNamedValueException) {
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