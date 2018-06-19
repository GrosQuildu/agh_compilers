
// Generated from /home/gros/studia/eaiib_3b/kompilatory/go_parser/Go2LLVM.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "Go2LLVMListener.h"


namespace go_parser {

/**
 * This class provides an empty implementation of Go2LLVMListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  Go2LLVMBaseListener : public Go2LLVMListener {
public:

  virtual void enterSourceFile(Go2LLVMParser::SourceFileContext * /*ctx*/) override { }
  virtual void exitSourceFile(Go2LLVMParser::SourceFileContext * /*ctx*/) override { }

  virtual void enterPackageClause(Go2LLVMParser::PackageClauseContext * /*ctx*/) override { }
  virtual void exitPackageClause(Go2LLVMParser::PackageClauseContext * /*ctx*/) override { }

  virtual void enterTopLevelDecl(Go2LLVMParser::TopLevelDeclContext * /*ctx*/) override { }
  virtual void exitTopLevelDecl(Go2LLVMParser::TopLevelDeclContext * /*ctx*/) override { }

  virtual void enterBlock(Go2LLVMParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(Go2LLVMParser::BlockContext * /*ctx*/) override { }

  virtual void enterType(Go2LLVMParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(Go2LLVMParser::TypeContext * /*ctx*/) override { }

  virtual void enterEos(Go2LLVMParser::EosContext * /*ctx*/) override { }
  virtual void exitEos(Go2LLVMParser::EosContext * /*ctx*/) override { }

  virtual void enterStatementList(Go2LLVMParser::StatementListContext * /*ctx*/) override { }
  virtual void exitStatementList(Go2LLVMParser::StatementListContext * /*ctx*/) override { }

  virtual void enterStatement(Go2LLVMParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(Go2LLVMParser::StatementContext * /*ctx*/) override { }

  virtual void enterIfStmt(Go2LLVMParser::IfStmtContext * /*ctx*/) override { }
  virtual void exitIfStmt(Go2LLVMParser::IfStmtContext * /*ctx*/) override { }

  virtual void enterReturnStmt(Go2LLVMParser::ReturnStmtContext * /*ctx*/) override { }
  virtual void exitReturnStmt(Go2LLVMParser::ReturnStmtContext * /*ctx*/) override { }

  virtual void enterSimpleStmt(Go2LLVMParser::SimpleStmtContext * /*ctx*/) override { }
  virtual void exitSimpleStmt(Go2LLVMParser::SimpleStmtContext * /*ctx*/) override { }

  virtual void enterAssignment(Go2LLVMParser::AssignmentContext * /*ctx*/) override { }
  virtual void exitAssignment(Go2LLVMParser::AssignmentContext * /*ctx*/) override { }

  virtual void enterEmptyStmt(Go2LLVMParser::EmptyStmtContext * /*ctx*/) override { }
  virtual void exitEmptyStmt(Go2LLVMParser::EmptyStmtContext * /*ctx*/) override { }

  virtual void enterDeclaration(Go2LLVMParser::DeclarationContext * /*ctx*/) override { }
  virtual void exitDeclaration(Go2LLVMParser::DeclarationContext * /*ctx*/) override { }

  virtual void enterIdentifierList(Go2LLVMParser::IdentifierListContext * /*ctx*/) override { }
  virtual void exitIdentifierList(Go2LLVMParser::IdentifierListContext * /*ctx*/) override { }

  virtual void enterExpression(Go2LLVMParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(Go2LLVMParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterUnaryExpr(Go2LLVMParser::UnaryExprContext * /*ctx*/) override { }
  virtual void exitUnaryExpr(Go2LLVMParser::UnaryExprContext * /*ctx*/) override { }

  virtual void enterExpressionList(Go2LLVMParser::ExpressionListContext * /*ctx*/) override { }
  virtual void exitExpressionList(Go2LLVMParser::ExpressionListContext * /*ctx*/) override { }

  virtual void enterOperandBasicLit(Go2LLVMParser::OperandBasicLitContext * /*ctx*/) override { }
  virtual void exitOperandBasicLit(Go2LLVMParser::OperandBasicLitContext * /*ctx*/) override { }

  virtual void enterOperandFunc(Go2LLVMParser::OperandFuncContext * /*ctx*/) override { }
  virtual void exitOperandFunc(Go2LLVMParser::OperandFuncContext * /*ctx*/) override { }

  virtual void enterOperandIdent(Go2LLVMParser::OperandIdentContext * /*ctx*/) override { }
  virtual void exitOperandIdent(Go2LLVMParser::OperandIdentContext * /*ctx*/) override { }

  virtual void enterOperandExp(Go2LLVMParser::OperandExpContext * /*ctx*/) override { }
  virtual void exitOperandExp(Go2LLVMParser::OperandExpContext * /*ctx*/) override { }

  virtual void enterArguments(Go2LLVMParser::ArgumentsContext * /*ctx*/) override { }
  virtual void exitArguments(Go2LLVMParser::ArgumentsContext * /*ctx*/) override { }

  virtual void enterBasicLit(Go2LLVMParser::BasicLitContext * /*ctx*/) override { }
  virtual void exitBasicLit(Go2LLVMParser::BasicLitContext * /*ctx*/) override { }

  virtual void enterFunctionDecl(Go2LLVMParser::FunctionDeclContext * /*ctx*/) override { }
  virtual void exitFunctionDecl(Go2LLVMParser::FunctionDeclContext * /*ctx*/) override { }

  virtual void enterSignature(Go2LLVMParser::SignatureContext * /*ctx*/) override { }
  virtual void exitSignature(Go2LLVMParser::SignatureContext * /*ctx*/) override { }

  virtual void enterResult(Go2LLVMParser::ResultContext * /*ctx*/) override { }
  virtual void exitResult(Go2LLVMParser::ResultContext * /*ctx*/) override { }

  virtual void enterParameters(Go2LLVMParser::ParametersContext * /*ctx*/) override { }
  virtual void exitParameters(Go2LLVMParser::ParametersContext * /*ctx*/) override { }

  virtual void enterParameterList(Go2LLVMParser::ParameterListContext * /*ctx*/) override { }
  virtual void exitParameterList(Go2LLVMParser::ParameterListContext * /*ctx*/) override { }

  virtual void enterParameterDecl(Go2LLVMParser::ParameterDeclContext * /*ctx*/) override { }
  virtual void exitParameterDecl(Go2LLVMParser::ParameterDeclContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace go_parser
