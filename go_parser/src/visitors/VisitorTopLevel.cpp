#include "Go2LLVMMyVisitor.h"

using namespace go_parser;
using namespace llvm;
using antlrcpp::Any;
using std::string;
using std::vector;
using std::pair;

/*
 * SourceFile = PackageClause Eos { TopLevelDecl Eos }
 * Return: nullptr
 */
Any Go2LLVMMyVisitor::visitSourceFile(Go2LLVMParser::SourceFileContext *ctx) {
    Go2LLVMError::line_no = ctx->getStart()->getLine();
    Go2LLVMError::Log("visitSourceFile: " + ctx->getText());

    // create main function, so we have global variables initializer block
    // main() void
    FunctionType *funcType = FunctionType::get(builder.getVoidTy(), false);
    Function *mainFunc = Function::Create(funcType, Function::ExternalLinkage, "main", module);
    BasicBlock *entrypoint = BasicBlock::Create(context, "main entrypoint", mainFunc);
    builder.SetInsertPoint(entrypoint);

    current_block = new MyBlock();

    for (auto topLevelDecl : ctx->topLevelDecl()) {
        topLevelDecl->accept(this);
    }

    if (!this->is_main_defined) {
        throw Go2LLVMError("Main function is not defined");
    }

    return nullptr;
}

/*
 * External function should be here somehow
 */
Any Go2LLVMMyVisitor::visitPackageClause(Go2LLVMParser::PackageClauseContext *ctx) {
    Go2LLVMError::line_no = ctx->getStart()->getLine();
    return visitChildren(ctx);
}

/*
 * TopLevelDecl = Declaration | FunctionDecl
 * Return: nullptr
 */
Any Go2LLVMMyVisitor::visitTopLevelDecl(Go2LLVMParser::TopLevelDeclContext *ctx) {
    Go2LLVMError::line_no = ctx->getStart()->getLine();
    Go2LLVMError::Log("visitTopLevelDecl: " + ctx->getText());

    // create global variables
    if (ctx->declaration() != nullptr) {
        vector<BasicVar *> variables = ctx->declaration()->accept(this);

        for (auto &variable : variables) {
            // create global in the module
            GlobalVariable *global_var = new GlobalVariable(*module, variable->getType(), false,
                                                            GlobalValue::LinkageTypes::InternalLinkage,
                                                            variable->getZeroValue(), variable->name);

            current_block->named_values[global_var->getName()] = var_factory.Get(global_var->getName(),
                                                                                 global_var->getType(), global_var);

            // initialize them at the beginning of the main function
            if (variable->getValue() != nullptr) {
                builder.CreateStore(variable->getValue(), global_var, false);
            }
        }
    }

    // create functions
    if (ctx->functionDecl() != nullptr) {
        ctx->functionDecl()->accept(this);
    }

    return nullptr;
}

/*
 * Type = IDENT_TOK
 * Return: Type*
 */
Any Go2LLVMMyVisitor::visitType(Go2LLVMParser::TypeContext *ctx) {
    Go2LLVMError::line_no = ctx->getStart()->getLine();

    string typeStr = ctx->IDENT_TOK()->getText();
    Type *type = var_factory.StringToType(typeStr);
    if (!type)
        throw Go2LLVMError("wrong type: " + typeStr);

    if (ctx->ptr_tok != nullptr) {
        return (Type *) llvm::PointerType::getUnqual(type);
    } else {
        return type;
    }
}

/*
 * Block = "{" StatementList "}"
 * Return: nullptr
 *
 * modifies builder and current_block
 */
Any Go2LLVMMyVisitor::visitBlock(Go2LLVMParser::BlockContext *ctx) {
    Go2LLVMError::line_no = ctx->getStart()->getLine();
    Go2LLVMError::Log("visitBlock: " + ctx->getText());

    Function *current_function = builder.GetInsertBlock()->getParent();
    MyBlock *previous_block = current_block;

    current_block = new MyBlock(previous_block);
    ctx->statementList()->accept(this);
    current_block = previous_block;

    return nullptr;
}

/*
 * Not used
 */
Any Go2LLVMMyVisitor::visitEos(Go2LLVMParser::EosContext *ctx) {
    Go2LLVMError::line_no = ctx->getStart()->getLine();
    return visitChildren(ctx);
}

