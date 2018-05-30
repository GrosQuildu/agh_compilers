
// Generated from /home/gros/studia/eaiib_3b/kompilatory/go_parser/Go2LLVM.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"


namespace go_parser {


class  Go2LLVMParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    STRING_TOK = 21, INT_TOK = 22, FLOAT_TOK = 23, IMAG_TOK = 24, UNARY_OP_TOK = 25, 
    BINARY_OP_TOK = 26, PACKAGE_TOK = 27, VAR_TOK = 28, FUNC_TOK = 29, RETURN_TOK = 30, 
    IF_TOK = 31, ELSE_TOK = 32, IDENT_TOK = 33, BO = 34, BC = 35, PO = 36, 
    PC = 37, SEMICOLON = 38, EQ = 39, COMMA = 40, WS = 41, COMMENT = 42, 
    LINE_COMMENT = 43, TERMINATOR = 44
  };

  enum {
    RuleSourceFile = 0, RulePackageClause = 1, RuleTopLevelDecl = 2, RuleBlock = 3, 
    RuleType = 4, RuleEos = 5, RuleStatementList = 6, RuleStatement = 7, 
    RuleIfStmt = 8, RuleReturnStmt = 9, RuleSimpleStmt = 10, RuleAssignment = 11, 
    RuleEmptyStmt = 12, RuleDeclaration = 13, RuleIdentifierList = 14, RuleExpression = 15, 
    RuleUnaryExpr = 16, RuleExpressionList = 17, RuleOperand = 18, RuleArguments = 19, 
    RuleBasicLit = 20, RuleFunctionDecl = 21, RuleSignature = 22, RuleResult = 23, 
    RuleParameters = 24, RuleParameterList = 25, RuleParameterDecl = 26
  };

  Go2LLVMParser(antlr4::TokenStream *input);
  ~Go2LLVMParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


      /**
      * Returns {@code true} iff on the current index of the parser's
      * token stream a token exists on the {@code HIDDEN} channel which
      * either is a line terminator, or is a multi line comment that
      * contains a line terminator.
      */
      bool lineTerminatorAhead() {
        // Get the token ahead of the current index.
        size_t possibleIndexEosToken = this->getCurrentToken()->getTokenIndex() - 1;
        antlr4::Token *ahead = _input->get(possibleIndexEosToken);
        if (ahead->getChannel() != antlr4::Lexer::HIDDEN) {
            return false;
        }

        if (ahead->getType() == TERMINATOR)
            return true;

        if (ahead->getType() == WS) {
            possibleIndexEosToken = this->getCurrentToken()->getTokenIndex() - 2;
            ahead = _input->get(possibleIndexEosToken);
        }

        std::string text = ahead->getText();
        size_t type = ahead->getType();

        return (type == COMMENT && (text.find("\r") != std::string::npos || text.find("\n") != std::string::npos)) || (type == TERMINATOR);
      }


  class SourceFileContext;
  class PackageClauseContext;
  class TopLevelDeclContext;
  class BlockContext;
  class TypeContext;
  class EosContext;
  class StatementListContext;
  class StatementContext;
  class IfStmtContext;
  class ReturnStmtContext;
  class SimpleStmtContext;
  class AssignmentContext;
  class EmptyStmtContext;
  class DeclarationContext;
  class IdentifierListContext;
  class ExpressionContext;
  class UnaryExprContext;
  class ExpressionListContext;
  class OperandContext;
  class ArgumentsContext;
  class BasicLitContext;
  class FunctionDeclContext;
  class SignatureContext;
  class ResultContext;
  class ParametersContext;
  class ParameterListContext;
  class ParameterDeclContext; 

  class  SourceFileContext : public antlr4::ParserRuleContext {
  public:
    SourceFileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PackageClauseContext *packageClause();
    std::vector<EosContext *> eos();
    EosContext* eos(size_t i);
    std::vector<TopLevelDeclContext *> topLevelDecl();
    TopLevelDeclContext* topLevelDecl(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SourceFileContext* sourceFile();

  class  PackageClauseContext : public antlr4::ParserRuleContext {
  public:
    PackageClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PACKAGE_TOK();
    antlr4::tree::TerminalNode *IDENT_TOK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PackageClauseContext* packageClause();

  class  TopLevelDeclContext : public antlr4::ParserRuleContext {
  public:
    TopLevelDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclarationContext *declaration();
    FunctionDeclContext *functionDecl();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TopLevelDeclContext* topLevelDecl();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BO();
    StatementListContext *statementList();
    antlr4::tree::TerminalNode *BC();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENT_TOK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeContext* type();

  class  EosContext : public antlr4::ParserRuleContext {
  public:
    EosContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *EOF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EosContext* eos();

  class  StatementListContext : public antlr4::ParserRuleContext {
  public:
    StatementListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    std::vector<EosContext *> eos();
    EosContext* eos(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementListContext* statementList();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclarationContext *declaration();
    SimpleStmtContext *simpleStmt();
    BlockContext *block();
    ReturnStmtContext *returnStmt();
    IfStmtContext *ifStmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  IfStmtContext : public antlr4::ParserRuleContext {
  public:
    IfStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF_TOK();
    ExpressionContext *expression();
    std::vector<BlockContext *> block();
    BlockContext* block(size_t i);
    SimpleStmtContext *simpleStmt();
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *ELSE_TOK();
    IfStmtContext *ifStmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IfStmtContext* ifStmt();

  class  ReturnStmtContext : public antlr4::ParserRuleContext {
  public:
    ReturnStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RETURN_TOK();
    ExpressionListContext *expressionList();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReturnStmtContext* returnStmt();

  class  SimpleStmtContext : public antlr4::ParserRuleContext {
  public:
    SimpleStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    AssignmentContext *assignment();
    EmptyStmtContext *emptyStmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SimpleStmtContext* simpleStmt();

  class  AssignmentContext : public antlr4::ParserRuleContext {
  public:
    AssignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierListContext *identifierList();
    antlr4::tree::TerminalNode *EQ();
    ExpressionListContext *expressionList();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignmentContext* assignment();

  class  EmptyStmtContext : public antlr4::ParserRuleContext {
  public:
    EmptyStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EmptyStmtContext* emptyStmt();

  class  DeclarationContext : public antlr4::ParserRuleContext {
  public:
    DeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VAR_TOK();
    IdentifierListContext *identifierList();
    TypeContext *type();
    antlr4::tree::TerminalNode *EQ();
    ExpressionListContext *expressionList();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclarationContext* declaration();

  class  IdentifierListContext : public antlr4::ParserRuleContext {
  public:
    IdentifierListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IDENT_TOK();
    antlr4::tree::TerminalNode* IDENT_TOK(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IdentifierListContext* identifierList();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    Go2LLVMParser::ExpressionContext *LE = nullptr;;
    antlr4::Token *binary_op_tok = nullptr;;
    Go2LLVMParser::ExpressionContext *RE = nullptr;;
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnaryExprContext *unaryExpr();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
  class  UnaryExprContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *unary_op_tok = nullptr;;
    UnaryExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OperandContext *operand();
    UnaryExprContext *unaryExpr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnaryExprContext* unaryExpr();

  class  ExpressionListContext : public antlr4::ParserRuleContext {
  public:
    ExpressionListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionListContext* expressionList();

  class  OperandContext : public antlr4::ParserRuleContext {
  public:
    OperandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    OperandContext() : antlr4::ParserRuleContext() { }
    void copyFrom(OperandContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  OperandBasicLitContext : public OperandContext {
  public:
    OperandBasicLitContext(OperandContext *ctx);

    BasicLitContext *basicLit();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  OperandIdentContext : public OperandContext {
  public:
    OperandIdentContext(OperandContext *ctx);

    antlr4::tree::TerminalNode *IDENT_TOK();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  OperandFuncContext : public OperandContext {
  public:
    OperandFuncContext(OperandContext *ctx);

    antlr4::tree::TerminalNode *IDENT_TOK();
    ArgumentsContext *arguments();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  OperandExpContext : public OperandContext {
  public:
    OperandExpContext(OperandContext *ctx);

    antlr4::tree::TerminalNode *PO();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *PC();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  OperandContext* operand();

  class  ArgumentsContext : public antlr4::ParserRuleContext {
  public:
    ArgumentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PO();
    antlr4::tree::TerminalNode *PC();
    ExpressionListContext *expressionList();
    antlr4::tree::TerminalNode *COMMA();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgumentsContext* arguments();

  class  BasicLitContext : public antlr4::ParserRuleContext {
  public:
    BasicLitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT_TOK();
    antlr4::tree::TerminalNode *FLOAT_TOK();
    antlr4::tree::TerminalNode *IMAG_TOK();
    antlr4::tree::TerminalNode *STRING_TOK();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BasicLitContext* basicLit();

  class  FunctionDeclContext : public antlr4::ParserRuleContext {
  public:
    FunctionDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FUNC_TOK();
    antlr4::tree::TerminalNode *IDENT_TOK();
    SignatureContext *signature();
    BlockContext *block();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionDeclContext* functionDecl();

  class  SignatureContext : public antlr4::ParserRuleContext {
  public:
    SignatureContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ParametersContext *parameters();
    ResultContext *result();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SignatureContext* signature();

  class  ResultContext : public antlr4::ParserRuleContext {
  public:
    ResultContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ParametersContext *parameters();
    TypeContext *type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ResultContext* result();

  class  ParametersContext : public antlr4::ParserRuleContext {
  public:
    ParametersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PO();
    antlr4::tree::TerminalNode *PC();
    ParameterListContext *parameterList();
    antlr4::tree::TerminalNode *COMMA();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParametersContext* parameters();

  class  ParameterListContext : public antlr4::ParserRuleContext {
  public:
    ParameterListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ParameterDeclContext *> parameterDecl();
    ParameterDeclContext* parameterDecl(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParameterListContext* parameterList();

  class  ParameterDeclContext : public antlr4::ParserRuleContext {
  public:
    ParameterDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdentifierListContext *identifierList();
    TypeContext *type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParameterDeclContext* parameterDecl();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool eosSempred(EosContext *_localctx, size_t predicateIndex);
  bool expressionSempred(ExpressionContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace go_parser
