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
    Go2LLVMError::line_no = ctx->getStart()->getLine();
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
    Go2LLVMError::line_no = ctx->getStart()->getLine();
    Go2LLVMError::Log("visitStatement: " + ctx->getText());
    current_block->DumpVariables();

    if (ctx->declaration() != nullptr) {
        vector<BasicVar*> variables = ctx->declaration()->accept(this);
        for (auto &variable : variables) {

            try {
                current_block->GetNamedValue(variable->name);
                throw Go2LLVMError("variable " + variable->name + " is already defined");
            } catch (NoNamedValueException) {}

            // Create an alloca for the variable
            BasicBlock *current_llvm_block = builder.GetInsertBlock();
            BasicBlock &entry_block = builder.GetInsertBlock()->getParent()->getEntryBlock();
            builder.SetInsertPoint(&entry_block);
            AllocaInst *alloca = builder.CreateAlloca(variable->getType(), 0, variable->name + ".addr");
            builder.SetInsertPoint(current_llvm_block);

            // Store the initial value into the alloca.
            if (variable->getValue() != nullptr) {
                builder.CreateStore(variable->getValue(), alloca);
            }

            // Add variable to block's symbol table.
            current_block->named_values[variable->name] = var_factory.Get(variable->name, alloca->getType(), alloca);

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
    Go2LLVMError::line_no = ctx->getStart()->getLine();

    BasicVar *cond_val = ctx->expression()->accept(this);
    BasicVar *cond_val_casted = var_factory.Get(cond_val->name, IntegerType::get(context, 1), cond_val->getValue());

    Function *function = builder.GetInsertBlock()->getParent();
    BasicBlock *if_bb = BasicBlock::Create(context, "if", function);
    BasicBlock *else_bb = BasicBlock::Create(context, "else");
    BasicBlock *merge_bb = BasicBlock::Create(context, "merge");

    if(ctx->ELSE_TOK() != nullptr)
        builder.CreateCondBr(cond_val_casted->getValue(), if_bb, else_bb);
    else
        builder.CreateCondBr(cond_val_casted->getValue(), if_bb, merge_bb);

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
    Go2LLVMError::line_no = ctx->getStart()->getLine();
    Go2LLVMError::Log("visitReturnStmt: " + ctx->getText());

    if (ctx->expressionList() != nullptr) {
        vector<BasicVar*> expressions = ctx->expressionList()->accept(this);

        // for now one value is returned
        for (auto expression : expressions) {
            BasicVar *variable = var_factory.Get("tmp_return_var", builder.getCurrentFunctionReturnType(), expression->getValue());
            builder.CreateRet(variable->getValue());
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
    Go2LLVMError::line_no = ctx->getStart()->getLine();
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
    Go2LLVMError::line_no = ctx->getStart()->getLine();
    Go2LLVMError::Log("visitAssignment: " + ctx->getText());

    vector<BasicVar*> identifiers = ctx->expressionList(0)->accept(this);
    vector<BasicVar*> assignments = ctx->expressionList(1)->accept(this);

    if (identifiers.size() != assignments.size())
        throw Go2LLVMError("identifiers list size != right hand side size");

    for (size_t i = 0; i < identifiers.size(); i++) {
        if(identifiers.at(i)->name.empty())
            throw Go2LLVMError("Variable name is empty");
        try {
            BasicVar *variable_ptr_value = current_block->GetNamedValue(identifiers.at(i)->name);
            if(!variable_ptr_value->getType()->isPointerTy())
                throw Go2LLVMError("Can't assign to " + identifiers.at(i)->name + ", it's not pointer type");

            if(variable_ptr_value->getType()->getContainedType(0)->isPointerTy()) {
                // alloca with pointer
                if(identifiers.at(i)->getType()->isPointerTy()) {
                    // just pointer, like: var p *int; p=&x;
                    builder.CreateStore(assignments.at(i)->getValue(), variable_ptr_value->getValue());
                } else {
                    // pointer dereferenced, like: var p *int; *p=3;
                    Value *load = builder.CreateLoad(variable_ptr_value->getValue(), "load_"+variable_ptr_value->name);
                    Type *raw_type = ((PointerType*)load->getType())->getElementType();
                    BasicVar *variable_new_value = var_factory.Get("tmp_assign_var", raw_type, assignments.at(i)->getValue());
                    builder.CreateStore(variable_new_value->getValue(), load);
                }
            } else {
                // alloca with normal value, , like: var p int; p = 5;
                Type *raw_type = ((PointerType*)variable_ptr_value->getType())->getElementType();
                BasicVar *variable_new_value = var_factory.Get("tmp_assign_var", raw_type, assignments.at(i)->getValue());
                builder.CreateStore(variable_new_value->getValue(), variable_ptr_value->getValue());
            }


        } catch (NoNamedValueException) {
            throw Go2LLVMError("unknown variable name " + identifiers.at(i)->name);
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