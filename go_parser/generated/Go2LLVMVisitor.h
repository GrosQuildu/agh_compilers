
// Generated from /home/gros/studia/eaiib_3b/kompilatory/go_parser/Go2LLVM.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "Go2LLVMParser.h"


namespace go_parser {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by Go2LLVMParser.
 */
class  Go2LLVMVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by Go2LLVMParser.
   */
    virtual antlrcpp::Any visitSourceFile(Go2LLVMParser::SourceFileContext *context) = 0;

    virtual antlrcpp::Any visitPackageClause(Go2LLVMParser::PackageClauseContext *context) = 0;

    virtual antlrcpp::Any visitTopLevelDecl(Go2LLVMParser::TopLevelDeclContext *context) = 0;

    virtual antlrcpp::Any visitBlock(Go2LLVMParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitType(Go2LLVMParser::TypeContext *context) = 0;

    virtual antlrcpp::Any visitEos(Go2LLVMParser::EosContext *context) = 0;

    virtual antlrcpp::Any visitStatementList(Go2LLVMParser::StatementListContext *context) = 0;

    virtual antlrcpp::Any visitStatement(Go2LLVMParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitIfStmt(Go2LLVMParser::IfStmtContext *context) = 0;

    virtual antlrcpp::Any visitReturnStmt(Go2LLVMParser::ReturnStmtContext *context) = 0;

    virtual antlrcpp::Any visitSimpleStmt(Go2LLVMParser::SimpleStmtContext *context) = 0;

    virtual antlrcpp::Any visitAssignment(Go2LLVMParser::AssignmentContext *context) = 0;

    virtual antlrcpp::Any visitEmptyStmt(Go2LLVMParser::EmptyStmtContext *context) = 0;

    virtual antlrcpp::Any visitDeclaration(Go2LLVMParser::DeclarationContext *context) = 0;

    virtual antlrcpp::Any visitIdentifierList(Go2LLVMParser::IdentifierListContext *context) = 0;

    virtual antlrcpp::Any visitExpression(Go2LLVMParser::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitUnaryExpr(Go2LLVMParser::UnaryExprContext *context) = 0;

    virtual antlrcpp::Any visitExpressionList(Go2LLVMParser::ExpressionListContext *context) = 0;

    virtual antlrcpp::Any visitOperandBasicLit(Go2LLVMParser::OperandBasicLitContext *context) = 0;

    virtual antlrcpp::Any visitOperandIdent(Go2LLVMParser::OperandIdentContext *context) = 0;

    virtual antlrcpp::Any visitOperandFunc(Go2LLVMParser::OperandFuncContext *context) = 0;

    virtual antlrcpp::Any visitOperandExp(Go2LLVMParser::OperandExpContext *context) = 0;

    virtual antlrcpp::Any visitArguments(Go2LLVMParser::ArgumentsContext *context) = 0;

    virtual antlrcpp::Any visitBasicLit(Go2LLVMParser::BasicLitContext *context) = 0;

    virtual antlrcpp::Any visitFunctionDecl(Go2LLVMParser::FunctionDeclContext *context) = 0;

    virtual antlrcpp::Any visitSignature(Go2LLVMParser::SignatureContext *context) = 0;

    virtual antlrcpp::Any visitResult(Go2LLVMParser::ResultContext *context) = 0;

    virtual antlrcpp::Any visitParameters(Go2LLVMParser::ParametersContext *context) = 0;

    virtual antlrcpp::Any visitParameterList(Go2LLVMParser::ParameterListContext *context) = 0;

    virtual antlrcpp::Any visitParameterDecl(Go2LLVMParser::ParameterDeclContext *context) = 0;


};

}  // namespace go_parser
