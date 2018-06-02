#include "Go2LLVMMyVisitor.h"
#include "MyBasicBlock.h"

using namespace go_parser;
using namespace llvm;
using antlrcpp::Any;
using std::string;
using std::vector;
using std::pair;

/*
 * SourceFile = PackageClause Eos { TopLevelDecl Eos }
 */
Any Go2LLVMMyVisitor::visitSourceFile(Go2LLVMParser::SourceFileContext *ctx) {
    parser_errors.Log("visitSourceFile: " + ctx->getText());

    // create main function, so we have global variables initializer block
    // main() void
    FunctionType *funcType = FunctionType::get(builder.getVoidTy(), false);
    Function *mainFunc = Function::Create(funcType, Function::ExternalLinkage, "main", module);
    BasicBlock *globals_initialization_block = BasicBlock::Create(context, "globals", mainFunc);
    builder.SetInsertPoint(globals_initialization_block);

    for(auto topLevelDecl : ctx->topLevelDecl()) {
        topLevelDecl->accept(this);
    }
    return std::string("done");
}

/*
 * External function should be here somehow
 */
Any Go2LLVMMyVisitor::visitPackageClause(Go2LLVMParser::PackageClauseContext *ctx) {
    return visitChildren(ctx);
}

    /*
     * TopLevelDecl = Declaration | FunctionDecl
     * Return: nullptr
     */
Any Go2LLVMMyVisitor::visitTopLevelDecl(Go2LLVMParser::TopLevelDeclContext *ctx) {
    parser_errors.Log("visitTopLevelDecl: " + ctx->getText());

    // create global variables
    if(ctx->declaration() != nullptr) {
        Any any_v = ctx->declaration()->accept(this);
        if(any_v.isNotNull()) {

            for(Variable &variable : any_v.as<vector<Variable>>()) {
                // create globals in the module
                module->getOrInsertGlobal(variable.name, builder.getInt32Ty());
                GlobalVariable *global_var = module->getGlobalVariable(variable.name);
                global_var->setInitializer(ConstantInt::get(context, APInt(32, 0, true)));

                // initialize them at the beginning of the main function
                if(variable.value != nullptr) {
                    builder.CreateStore(variable.value, global_var, false);
                }
            }
        }
    }

    // create functions
    if(ctx->functionDecl() != nullptr) {
        ctx->functionDecl()->accept(this);
    }

    return nullptr;
}

/*
 * Type = IDENT_TOK
 * Return: string - type
 */
Any Go2LLVMMyVisitor::visitType(Go2LLVMParser::TypeContext *ctx) {
    return ctx->IDENT_TOK()->getText();
}

/*
 * Block = "{" StatementList "}"
 * Return: nullptr
 *
 * modifies builder and current_block
 */
Any Go2LLVMMyVisitor::visitBlock(Go2LLVMParser::BlockContext *ctx) {
    parser_errors.Log("visitBlock: " + ctx->getText());

    Function *current_function = builder.GetInsertBlock()->getParent();
    BasicBlock *new_block = BasicBlock::Create(context, "new_block", current_function);
    MyBasicBlock *previous_block = current_block;

    if(builder.GetInsertBlock() != current_block->block) {
        return parser_errors.AddError(ctx->getStart()->getLine(), "block mismatch");
    }

    builder.SetInsertPoint(new_block);
    current_block = new MyBasicBlock(current_function, new_block, previous_block);

    ctx->statementList()->accept(this);

    builder.SetInsertPoint(previous_block->block);
    current_block = previous_block;

    return nullptr;
}

/*
 * not used
 */
Any Go2LLVMMyVisitor::visitEos(Go2LLVMParser::EosContext *ctx) {
    return visitChildren(ctx);
}

