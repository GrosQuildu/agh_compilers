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
    BasicBlock *entrypoint = BasicBlock::Create(context, "main entrypoint", mainFunc);
    builder.SetInsertPoint(entrypoint);

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
 * Return: nullptr | Type*
 */
Any Go2LLVMMyVisitor::visitType(Go2LLVMParser::TypeContext *ctx) {
    string typeStr = ctx->IDENT_TOK()->getText();
    Type *result = Variable::TypeFromStr(context, typeStr);
    if(!result)
        return parser_errors.AddError(ctx->getStart()->getLine(), "wrong type: " + typeStr);
    return result;
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
    MyBasicBlock *previous_block = current_block;

    current_block = new MyBasicBlock(current_function, previous_block);
    ctx->statementList()->accept(this);
    current_block = previous_block;

    return nullptr;
}

/*
 * not used
 */
Any Go2LLVMMyVisitor::visitEos(Go2LLVMParser::EosContext *ctx) {
    return visitChildren(ctx);
}

