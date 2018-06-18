
// Generated from Go2LLVM.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "Go2LLVMParser.h"


namespace go_parser {

/**
 * This interface defines an abstract listener for a parse tree produced by Go2LLVMParser.
 */
class  Go2LLVMListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterSourceFile(Go2LLVMParser::SourceFileContext *ctx) = 0;
  virtual void exitSourceFile(Go2LLVMParser::SourceFileContext *ctx) = 0;

  virtual void enterPackageClause(Go2LLVMParser::PackageClauseContext *ctx) = 0;
  virtual void exitPackageClause(Go2LLVMParser::PackageClauseContext *ctx) = 0;

  virtual void enterTopLevelDecl(Go2LLVMParser::TopLevelDeclContext *ctx) = 0;
  virtual void exitTopLevelDecl(Go2LLVMParser::TopLevelDeclContext *ctx) = 0;

  virtual void enterBlock(Go2LLVMParser::BlockContext *ctx) = 0;
  virtual void exitBlock(Go2LLVMParser::BlockContext *ctx) = 0;

  virtual void enterType(Go2LLVMParser::TypeContext *ctx) = 0;
  virtual void exitType(Go2LLVMParser::TypeContext *ctx) = 0;

  virtual void enterEos(Go2LLVMParser::EosContext *ctx) = 0;
  virtual void exitEos(Go2LLVMParser::EosContext *ctx) = 0;

  virtual void enterStatementList(Go2LLVMParser::StatementListContext *ctx) = 0;
  virtual void exitStatementList(Go2LLVMParser::StatementListContext *ctx) = 0;

  virtual void enterStatement(Go2LLVMParser::StatementContext *ctx) = 0;
  virtual void exitStatement(Go2LLVMParser::StatementContext *ctx) = 0;

  virtual void enterIfStmt(Go2LLVMParser::IfStmtContext *ctx) = 0;
  virtual void exitIfStmt(Go2LLVMParser::IfStmtContext *ctx) = 0;

  virtual void enterReturnStmt(Go2LLVMParser::ReturnStmtContext *ctx) = 0;
  virtual void exitReturnStmt(Go2LLVMParser::ReturnStmtContext *ctx) = 0;

  virtual void enterSimpleStmt(Go2LLVMParser::SimpleStmtContext *ctx) = 0;
  virtual void exitSimpleStmt(Go2LLVMParser::SimpleStmtContext *ctx) = 0;

  virtual void enterAssignment(Go2LLVMParser::AssignmentContext *ctx) = 0;
  virtual void exitAssignment(Go2LLVMParser::AssignmentContext *ctx) = 0;

  virtual void enterEmptyStmt(Go2LLVMParser::EmptyStmtContext *ctx) = 0;
  virtual void exitEmptyStmt(Go2LLVMParser::EmptyStmtContext *ctx) = 0;

  virtual void enterDeclaration(Go2LLVMParser::DeclarationContext *ctx) = 0;
  virtual void exitDeclaration(Go2LLVMParser::DeclarationContext *ctx) = 0;

  virtual void enterIdentifierList(Go2LLVMParser::IdentifierListContext *ctx) = 0;
  virtual void exitIdentifierList(Go2LLVMParser::IdentifierListContext *ctx) = 0;

  virtual void enterExpression(Go2LLVMParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(Go2LLVMParser::ExpressionContext *ctx) = 0;

  virtual void enterUnaryExpr(Go2LLVMParser::UnaryExprContext *ctx) = 0;
  virtual void exitUnaryExpr(Go2LLVMParser::UnaryExprContext *ctx) = 0;

  virtual void enterExpressionList(Go2LLVMParser::ExpressionListContext *ctx) = 0;
  virtual void exitExpressionList(Go2LLVMParser::ExpressionListContext *ctx) = 0;

  virtual void enterOperandBasicLit(Go2LLVMParser::OperandBasicLitContext *ctx) = 0;
  virtual void exitOperandBasicLit(Go2LLVMParser::OperandBasicLitContext *ctx) = 0;

  virtual void enterOperandFunc(Go2LLVMParser::OperandFuncContext *ctx) = 0;
  virtual void exitOperandFunc(Go2LLVMParser::OperandFuncContext *ctx) = 0;

  virtual void enterOperandIdent(Go2LLVMParser::OperandIdentContext *ctx) = 0;
  virtual void exitOperandIdent(Go2LLVMParser::OperandIdentContext *ctx) = 0;

  virtual void enterOperandExp(Go2LLVMParser::OperandExpContext *ctx) = 0;
  virtual void exitOperandExp(Go2LLVMParser::OperandExpContext *ctx) = 0;

  virtual void enterArguments(Go2LLVMParser::ArgumentsContext *ctx) = 0;
  virtual void exitArguments(Go2LLVMParser::ArgumentsContext *ctx) = 0;

  virtual void enterBasicLit(Go2LLVMParser::BasicLitContext *ctx) = 0;
  virtual void exitBasicLit(Go2LLVMParser::BasicLitContext *ctx) = 0;

  virtual void enterFunctionDecl(Go2LLVMParser::FunctionDeclContext *ctx) = 0;
  virtual void exitFunctionDecl(Go2LLVMParser::FunctionDeclContext *ctx) = 0;

  virtual void enterSignature(Go2LLVMParser::SignatureContext *ctx) = 0;
  virtual void exitSignature(Go2LLVMParser::SignatureContext *ctx) = 0;

  virtual void enterResult(Go2LLVMParser::ResultContext *ctx) = 0;
  virtual void exitResult(Go2LLVMParser::ResultContext *ctx) = 0;

  virtual void enterParameters(Go2LLVMParser::ParametersContext *ctx) = 0;
  virtual void exitParameters(Go2LLVMParser::ParametersContext *ctx) = 0;

  virtual void enterParameterList(Go2LLVMParser::ParameterListContext *ctx) = 0;
  virtual void exitParameterList(Go2LLVMParser::ParameterListContext *ctx) = 0;

  virtual void enterParameterDecl(Go2LLVMParser::ParameterDeclContext *ctx) = 0;
  virtual void exitParameterDecl(Go2LLVMParser::ParameterDeclContext *ctx) = 0;


};

}  // namespace go_parser
