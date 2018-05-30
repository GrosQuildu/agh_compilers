#include "Go2LLVMMyVisitor.h"

using namespace go_parser;
using namespace llvm;
using antlrcpp::Any;
using std::string;
using std::vector;
using std::pair;

Any Go2LLVMMyVisitor::visitSourceFile(Go2LLVMParser::SourceFileContext *ctx) {
    parser_errors.Log("visitSourceFile: " + ctx->getText());

    for(auto topLevelDecl : ctx->topLevelDecl()) {
        topLevelDecl->accept(this);
    }
    return std::string("done");
}

Any Go2LLVMMyVisitor::visitPackageClause(Go2LLVMParser::PackageClauseContext *ctx) {
    return visitChildren(ctx);
}

Any Go2LLVMMyVisitor::visitTopLevelDecl(Go2LLVMParser::TopLevelDeclContext *ctx) {
    parser_errors.Log("visitTopLevelDecl: " + ctx->getText());

    // populate global named_values map
    if(ctx->declaration() != nullptr) {
        ctx->declaration()->accept(this);
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
 * Return:
 */
Any Go2LLVMMyVisitor::visitBlock(Go2LLVMParser::BlockContext *ctx) {
    parser_errors.Log("visitBlock: " + ctx->getText());
    ctx->statementList()->accept(this);
}

Any Go2LLVMMyVisitor::visitEos(Go2LLVMParser::EosContext *ctx) {
    return visitChildren(ctx);
}

