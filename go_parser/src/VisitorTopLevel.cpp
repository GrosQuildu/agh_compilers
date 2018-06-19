#include "Go2LLVMMyVisitor.h"
#include "Helpers.h"

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
    Go2LLVMError::Log("visitSourceFile: " + ctx->getText());

    // create main function, so we have global variables initializer block
    // main() void
    FunctionType *funcType = FunctionType::get(builder.getVoidTy(), false);
    Function *mainFunc = Function::Create(funcType, Function::ExternalLinkage, "main", module);
    BasicBlock *entrypoint = BasicBlock::Create(context, "main entrypoint", mainFunc);
    builder.SetInsertPoint(entrypoint);

    for(auto topLevelDecl : ctx->topLevelDecl()) {
        topLevelDecl->accept(this);
    }

    if(!this->is_main_defined) {
        throw Go2LLVMError("Main function is not defined");
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
    Go2LLVMError::Log("visitTopLevelDecl: " + ctx->getText());

    // create global variables
    if(ctx->declaration() != nullptr) {
        vector<Variable> variables = ctx->declaration()->accept(this);

        for(auto &variable : variables) {
            // global init value
            Constant *init_val;
            if(variable.type->isFloatingPointTy())
                init_val = ConstantFP::getZeroValueForNegation(variable.type);
            else if(variable.type->isIntegerTy())
                init_val = ConstantInt::get(context, APInt(variable.type->getIntegerBitWidth(), 0));
            else
                throw Go2LLVMError(ctx->getStart()->getLine(), "Unknown type");

            // create global in the module
            GlobalVariable *global_var = new GlobalVariable(*module, variable.type, false,
                                                            GlobalValue::LinkageTypes::InternalLinkage, init_val, variable.name);

            // initialize them at the beginning of the main function
            if(variable.value != nullptr) {
                variable.value = Variable::CastL2R(ctx->getStart()->getLine(), builder, variable.value, variable.type);
                builder.CreateStore(variable.value, global_var, false);
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
    Type *type = Variable::TypeFromStr(context, typeStr);
    if(!type)
        throw Go2LLVMError(ctx->getStart()->getLine(), "wrong type: " + typeStr);

    if(ctx->ptr_tok != nullptr) {
        return (Type*)llvm::PointerType::getUnqual(type);
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
    Go2LLVMError::Log("visitBlock: " + ctx->getText());

    Function *current_function = builder.GetInsertBlock()->getParent();
    MyBlock *previous_block = current_block;

    current_block = new MyBlock(current_function, previous_block);
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

