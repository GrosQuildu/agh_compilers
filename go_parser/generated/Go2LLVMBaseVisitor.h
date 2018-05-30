
// Generated from /home/gros/studia/eaiib_3b/kompilatory/go_parser/Go2LLVM.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "Go2LLVMVisitor.h"


namespace go_parser {

/**
 * This class provides an empty implementation of Go2LLVMVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  Go2LLVMBaseVisitor : public Go2LLVMVisitor {
public:

  virtual antlrcpp::Any visitSourceFile(Go2LLVMParser::SourceFileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPackageClause(Go2LLVMParser::PackageClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTopLevelDecl(Go2LLVMParser::TopLevelDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock(Go2LLVMParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType(Go2LLVMParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEos(Go2LLVMParser::EosContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatementList(Go2LLVMParser::StatementListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(Go2LLVMParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfStmt(Go2LLVMParser::IfStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReturnStmt(Go2LLVMParser::ReturnStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimpleStmt(Go2LLVMParser::SimpleStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignment(Go2LLVMParser::AssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEmptyStmt(Go2LLVMParser::EmptyStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclaration(Go2LLVMParser::DeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdentifierList(Go2LLVMParser::IdentifierListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression(Go2LLVMParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryExpr(Go2LLVMParser::UnaryExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpressionList(Go2LLVMParser::ExpressionListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOperandBasicLit(Go2LLVMParser::OperandBasicLitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOperandIdent(Go2LLVMParser::OperandIdentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOperandFunc(Go2LLVMParser::OperandFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOperandExp(Go2LLVMParser::OperandExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArguments(Go2LLVMParser::ArgumentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBasicLit(Go2LLVMParser::BasicLitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionDecl(Go2LLVMParser::FunctionDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSignature(Go2LLVMParser::SignatureContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitResult(Go2LLVMParser::ResultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameters(Go2LLVMParser::ParametersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameterList(Go2LLVMParser::ParameterListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameterDecl(Go2LLVMParser::ParameterDeclContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace go_parser
