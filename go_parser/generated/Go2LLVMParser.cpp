
// Generated from /home/gros/studia/eaiib_3b/kompilatory/go_parser/Go2LLVM.g4 by ANTLR 4.7.1


#include "Go2LLVMListener.h"
#include "Go2LLVMVisitor.h"

#include "Go2LLVMParser.h"


using namespace antlrcpp;
using namespace go_parser;
using namespace antlr4;

Go2LLVMParser::Go2LLVMParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

Go2LLVMParser::~Go2LLVMParser() {
  delete _interpreter;
}

std::string Go2LLVMParser::getGrammarFileName() const {
  return "Go2LLVM.g4";
}

const std::vector<std::string>& Go2LLVMParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& Go2LLVMParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- SourceFileContext ------------------------------------------------------------------

Go2LLVMParser::SourceFileContext::SourceFileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Go2LLVMParser::PackageClauseContext* Go2LLVMParser::SourceFileContext::packageClause() {
  return getRuleContext<Go2LLVMParser::PackageClauseContext>(0);
}

std::vector<Go2LLVMParser::EosContext *> Go2LLVMParser::SourceFileContext::eos() {
  return getRuleContexts<Go2LLVMParser::EosContext>();
}

Go2LLVMParser::EosContext* Go2LLVMParser::SourceFileContext::eos(size_t i) {
  return getRuleContext<Go2LLVMParser::EosContext>(i);
}

std::vector<Go2LLVMParser::TopLevelDeclContext *> Go2LLVMParser::SourceFileContext::topLevelDecl() {
  return getRuleContexts<Go2LLVMParser::TopLevelDeclContext>();
}

Go2LLVMParser::TopLevelDeclContext* Go2LLVMParser::SourceFileContext::topLevelDecl(size_t i) {
  return getRuleContext<Go2LLVMParser::TopLevelDeclContext>(i);
}


size_t Go2LLVMParser::SourceFileContext::getRuleIndex() const {
  return Go2LLVMParser::RuleSourceFile;
}

void Go2LLVMParser::SourceFileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSourceFile(this);
}

void Go2LLVMParser::SourceFileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSourceFile(this);
}


antlrcpp::Any Go2LLVMParser::SourceFileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Go2LLVMVisitor*>(visitor))
    return parserVisitor->visitSourceFile(this);
  else
    return visitor->visitChildren(this);
}

Go2LLVMParser::SourceFileContext* Go2LLVMParser::sourceFile() {
  SourceFileContext *_localctx = _tracker.createInstance<SourceFileContext>(_ctx, getState());
  enterRule(_localctx, 0, Go2LLVMParser::RuleSourceFile);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(54);
    packageClause();
    setState(55);
    eos();
    setState(61);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Go2LLVMParser::VAR_TOK

    || _la == Go2LLVMParser::FUNC_TOK) {
      setState(56);
      topLevelDecl();
      setState(57);
      eos();
      setState(63);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PackageClauseContext ------------------------------------------------------------------

Go2LLVMParser::PackageClauseContext::PackageClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Go2LLVMParser::PackageClauseContext::PACKAGE_TOK() {
  return getToken(Go2LLVMParser::PACKAGE_TOK, 0);
}

tree::TerminalNode* Go2LLVMParser::PackageClauseContext::IDENT_TOK() {
  return getToken(Go2LLVMParser::IDENT_TOK, 0);
}


size_t Go2LLVMParser::PackageClauseContext::getRuleIndex() const {
  return Go2LLVMParser::RulePackageClause;
}

void Go2LLVMParser::PackageClauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPackageClause(this);
}

void Go2LLVMParser::PackageClauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPackageClause(this);
}


antlrcpp::Any Go2LLVMParser::PackageClauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Go2LLVMVisitor*>(visitor))
    return parserVisitor->visitPackageClause(this);
  else
    return visitor->visitChildren(this);
}

Go2LLVMParser::PackageClauseContext* Go2LLVMParser::packageClause() {
  PackageClauseContext *_localctx = _tracker.createInstance<PackageClauseContext>(_ctx, getState());
  enterRule(_localctx, 2, Go2LLVMParser::RulePackageClause);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(64);
    match(Go2LLVMParser::PACKAGE_TOK);
    setState(65);
    match(Go2LLVMParser::IDENT_TOK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TopLevelDeclContext ------------------------------------------------------------------

Go2LLVMParser::TopLevelDeclContext::TopLevelDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Go2LLVMParser::DeclarationContext* Go2LLVMParser::TopLevelDeclContext::declaration() {
  return getRuleContext<Go2LLVMParser::DeclarationContext>(0);
}

Go2LLVMParser::FunctionDeclContext* Go2LLVMParser::TopLevelDeclContext::functionDecl() {
  return getRuleContext<Go2LLVMParser::FunctionDeclContext>(0);
}


size_t Go2LLVMParser::TopLevelDeclContext::getRuleIndex() const {
  return Go2LLVMParser::RuleTopLevelDecl;
}

void Go2LLVMParser::TopLevelDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTopLevelDecl(this);
}

void Go2LLVMParser::TopLevelDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTopLevelDecl(this);
}


antlrcpp::Any Go2LLVMParser::TopLevelDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Go2LLVMVisitor*>(visitor))
    return parserVisitor->visitTopLevelDecl(this);
  else
    return visitor->visitChildren(this);
}

Go2LLVMParser::TopLevelDeclContext* Go2LLVMParser::topLevelDecl() {
  TopLevelDeclContext *_localctx = _tracker.createInstance<TopLevelDeclContext>(_ctx, getState());
  enterRule(_localctx, 4, Go2LLVMParser::RuleTopLevelDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(69);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Go2LLVMParser::VAR_TOK: {
        enterOuterAlt(_localctx, 1);
        setState(67);
        declaration();
        break;
      }

      case Go2LLVMParser::FUNC_TOK: {
        enterOuterAlt(_localctx, 2);
        setState(68);
        functionDecl();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

Go2LLVMParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Go2LLVMParser::BlockContext::BO() {
  return getToken(Go2LLVMParser::BO, 0);
}

Go2LLVMParser::StatementListContext* Go2LLVMParser::BlockContext::statementList() {
  return getRuleContext<Go2LLVMParser::StatementListContext>(0);
}

tree::TerminalNode* Go2LLVMParser::BlockContext::BC() {
  return getToken(Go2LLVMParser::BC, 0);
}


size_t Go2LLVMParser::BlockContext::getRuleIndex() const {
  return Go2LLVMParser::RuleBlock;
}

void Go2LLVMParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void Go2LLVMParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


antlrcpp::Any Go2LLVMParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Go2LLVMVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

Go2LLVMParser::BlockContext* Go2LLVMParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 6, Go2LLVMParser::RuleBlock);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(71);
    match(Go2LLVMParser::BO);
    setState(72);
    statementList();
    setState(73);
    match(Go2LLVMParser::BC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementListContext ------------------------------------------------------------------

Go2LLVMParser::StatementListContext::StatementListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<Go2LLVMParser::StatementContext *> Go2LLVMParser::StatementListContext::statement() {
  return getRuleContexts<Go2LLVMParser::StatementContext>();
}

Go2LLVMParser::StatementContext* Go2LLVMParser::StatementListContext::statement(size_t i) {
  return getRuleContext<Go2LLVMParser::StatementContext>(i);
}

std::vector<Go2LLVMParser::EosContext *> Go2LLVMParser::StatementListContext::eos() {
  return getRuleContexts<Go2LLVMParser::EosContext>();
}

Go2LLVMParser::EosContext* Go2LLVMParser::StatementListContext::eos(size_t i) {
  return getRuleContext<Go2LLVMParser::EosContext>(i);
}


size_t Go2LLVMParser::StatementListContext::getRuleIndex() const {
  return Go2LLVMParser::RuleStatementList;
}

void Go2LLVMParser::StatementListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatementList(this);
}

void Go2LLVMParser::StatementListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatementList(this);
}


antlrcpp::Any Go2LLVMParser::StatementListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Go2LLVMVisitor*>(visitor))
    return parserVisitor->visitStatementList(this);
  else
    return visitor->visitChildren(this);
}

Go2LLVMParser::StatementListContext* Go2LLVMParser::statementList() {
  StatementListContext *_localctx = _tracker.createInstance<StatementListContext>(_ctx, getState());
  enterRule(_localctx, 8, Go2LLVMParser::RuleStatementList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(80);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << Go2LLVMParser::T__8)
      | (1ULL << Go2LLVMParser::T__9)
      | (1ULL << Go2LLVMParser::T__11)
      | (1ULL << Go2LLVMParser::T__12)
      | (1ULL << Go2LLVMParser::T__17)
      | (1ULL << Go2LLVMParser::T__19)
      | (1ULL << Go2LLVMParser::STRING_TOK)
      | (1ULL << Go2LLVMParser::INT_TOK)
      | (1ULL << Go2LLVMParser::FLOAT_TOK)
      | (1ULL << Go2LLVMParser::IMAG_TOK)
      | (1ULL << Go2LLVMParser::VAR_TOK)
      | (1ULL << Go2LLVMParser::RETURN_TOK)
      | (1ULL << Go2LLVMParser::IF_TOK)
      | (1ULL << Go2LLVMParser::IDENT_TOK)
      | (1ULL << Go2LLVMParser::BO)
      | (1ULL << Go2LLVMParser::PO)
      | (1ULL << Go2LLVMParser::SEMICOLON))) != 0)) {
      setState(75);
      statement();
      setState(76);
      eos();
      setState(82);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

Go2LLVMParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Go2LLVMParser::DeclarationContext* Go2LLVMParser::StatementContext::declaration() {
  return getRuleContext<Go2LLVMParser::DeclarationContext>(0);
}

Go2LLVMParser::SimpleStmtContext* Go2LLVMParser::StatementContext::simpleStmt() {
  return getRuleContext<Go2LLVMParser::SimpleStmtContext>(0);
}

Go2LLVMParser::BlockContext* Go2LLVMParser::StatementContext::block() {
  return getRuleContext<Go2LLVMParser::BlockContext>(0);
}

Go2LLVMParser::ReturnStmtContext* Go2LLVMParser::StatementContext::returnStmt() {
  return getRuleContext<Go2LLVMParser::ReturnStmtContext>(0);
}

Go2LLVMParser::IfStmtContext* Go2LLVMParser::StatementContext::ifStmt() {
  return getRuleContext<Go2LLVMParser::IfStmtContext>(0);
}


size_t Go2LLVMParser::StatementContext::getRuleIndex() const {
  return Go2LLVMParser::RuleStatement;
}

void Go2LLVMParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void Go2LLVMParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


antlrcpp::Any Go2LLVMParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Go2LLVMVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

Go2LLVMParser::StatementContext* Go2LLVMParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 10, Go2LLVMParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(88);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Go2LLVMParser::VAR_TOK: {
        enterOuterAlt(_localctx, 1);
        setState(83);
        declaration();
        break;
      }

      case Go2LLVMParser::T__8:
      case Go2LLVMParser::T__9:
      case Go2LLVMParser::T__11:
      case Go2LLVMParser::T__12:
      case Go2LLVMParser::T__17:
      case Go2LLVMParser::T__19:
      case Go2LLVMParser::STRING_TOK:
      case Go2LLVMParser::INT_TOK:
      case Go2LLVMParser::FLOAT_TOK:
      case Go2LLVMParser::IMAG_TOK:
      case Go2LLVMParser::IDENT_TOK:
      case Go2LLVMParser::PO:
      case Go2LLVMParser::SEMICOLON: {
        enterOuterAlt(_localctx, 2);
        setState(84);
        simpleStmt();
        break;
      }

      case Go2LLVMParser::BO: {
        enterOuterAlt(_localctx, 3);
        setState(85);
        block();
        break;
      }

      case Go2LLVMParser::RETURN_TOK: {
        enterOuterAlt(_localctx, 4);
        setState(86);
        returnStmt();
        break;
      }

      case Go2LLVMParser::IF_TOK: {
        enterOuterAlt(_localctx, 5);
        setState(87);
        ifStmt();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStmtContext ------------------------------------------------------------------

Go2LLVMParser::IfStmtContext::IfStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Go2LLVMParser::IfStmtContext::IF_TOK() {
  return getToken(Go2LLVMParser::IF_TOK, 0);
}

Go2LLVMParser::ExpressionContext* Go2LLVMParser::IfStmtContext::expression() {
  return getRuleContext<Go2LLVMParser::ExpressionContext>(0);
}

std::vector<Go2LLVMParser::BlockContext *> Go2LLVMParser::IfStmtContext::block() {
  return getRuleContexts<Go2LLVMParser::BlockContext>();
}

Go2LLVMParser::BlockContext* Go2LLVMParser::IfStmtContext::block(size_t i) {
  return getRuleContext<Go2LLVMParser::BlockContext>(i);
}

Go2LLVMParser::SimpleStmtContext* Go2LLVMParser::IfStmtContext::simpleStmt() {
  return getRuleContext<Go2LLVMParser::SimpleStmtContext>(0);
}

tree::TerminalNode* Go2LLVMParser::IfStmtContext::SEMICOLON() {
  return getToken(Go2LLVMParser::SEMICOLON, 0);
}

tree::TerminalNode* Go2LLVMParser::IfStmtContext::ELSE_TOK() {
  return getToken(Go2LLVMParser::ELSE_TOK, 0);
}

Go2LLVMParser::IfStmtContext* Go2LLVMParser::IfStmtContext::ifStmt() {
  return getRuleContext<Go2LLVMParser::IfStmtContext>(0);
}


size_t Go2LLVMParser::IfStmtContext::getRuleIndex() const {
  return Go2LLVMParser::RuleIfStmt;
}

void Go2LLVMParser::IfStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStmt(this);
}

void Go2LLVMParser::IfStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStmt(this);
}


antlrcpp::Any Go2LLVMParser::IfStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Go2LLVMVisitor*>(visitor))
    return parserVisitor->visitIfStmt(this);
  else
    return visitor->visitChildren(this);
}

Go2LLVMParser::IfStmtContext* Go2LLVMParser::ifStmt() {
  IfStmtContext *_localctx = _tracker.createInstance<IfStmtContext>(_ctx, getState());
  enterRule(_localctx, 12, Go2LLVMParser::RuleIfStmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(90);
    match(Go2LLVMParser::IF_TOK);
    setState(94);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      setState(91);
      simpleStmt();
      setState(92);
      match(Go2LLVMParser::SEMICOLON);
      break;
    }

    }
    setState(96);
    expression(0);
    setState(97);
    block();
    setState(103);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Go2LLVMParser::ELSE_TOK) {
      setState(98);
      match(Go2LLVMParser::ELSE_TOK);
      setState(101);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case Go2LLVMParser::IF_TOK: {
          setState(99);
          ifStmt();
          break;
        }

        case Go2LLVMParser::BO: {
          setState(100);
          block();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStmtContext ------------------------------------------------------------------

Go2LLVMParser::ReturnStmtContext::ReturnStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Go2LLVMParser::ReturnStmtContext::RETURN_TOK() {
  return getToken(Go2LLVMParser::RETURN_TOK, 0);
}

Go2LLVMParser::ExpressionListContext* Go2LLVMParser::ReturnStmtContext::expressionList() {
  return getRuleContext<Go2LLVMParser::ExpressionListContext>(0);
}


size_t Go2LLVMParser::ReturnStmtContext::getRuleIndex() const {
  return Go2LLVMParser::RuleReturnStmt;
}

void Go2LLVMParser::ReturnStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStmt(this);
}

void Go2LLVMParser::ReturnStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStmt(this);
}


antlrcpp::Any Go2LLVMParser::ReturnStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Go2LLVMVisitor*>(visitor))
    return parserVisitor->visitReturnStmt(this);
  else
    return visitor->visitChildren(this);
}

Go2LLVMParser::ReturnStmtContext* Go2LLVMParser::returnStmt() {
  ReturnStmtContext *_localctx = _tracker.createInstance<ReturnStmtContext>(_ctx, getState());
  enterRule(_localctx, 14, Go2LLVMParser::RuleReturnStmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(105);
    match(Go2LLVMParser::RETURN_TOK);
    setState(107);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << Go2LLVMParser::T__8)
      | (1ULL << Go2LLVMParser::T__9)
      | (1ULL << Go2LLVMParser::T__11)
      | (1ULL << Go2LLVMParser::T__12)
      | (1ULL << Go2LLVMParser::T__17)
      | (1ULL << Go2LLVMParser::T__19)
      | (1ULL << Go2LLVMParser::STRING_TOK)
      | (1ULL << Go2LLVMParser::INT_TOK)
      | (1ULL << Go2LLVMParser::FLOAT_TOK)
      | (1ULL << Go2LLVMParser::IMAG_TOK)
      | (1ULL << Go2LLVMParser::IDENT_TOK)
      | (1ULL << Go2LLVMParser::PO))) != 0)) {
      setState(106);
      expressionList();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SimpleStmtContext ------------------------------------------------------------------

Go2LLVMParser::SimpleStmtContext::SimpleStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Go2LLVMParser::ExpressionContext* Go2LLVMParser::SimpleStmtContext::expression() {
  return getRuleContext<Go2LLVMParser::ExpressionContext>(0);
}

Go2LLVMParser::AssignmentContext* Go2LLVMParser::SimpleStmtContext::assignment() {
  return getRuleContext<Go2LLVMParser::AssignmentContext>(0);
}

Go2LLVMParser::EmptyStmtContext* Go2LLVMParser::SimpleStmtContext::emptyStmt() {
  return getRuleContext<Go2LLVMParser::EmptyStmtContext>(0);
}


size_t Go2LLVMParser::SimpleStmtContext::getRuleIndex() const {
  return Go2LLVMParser::RuleSimpleStmt;
}

void Go2LLVMParser::SimpleStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimpleStmt(this);
}

void Go2LLVMParser::SimpleStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimpleStmt(this);
}


antlrcpp::Any Go2LLVMParser::SimpleStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Go2LLVMVisitor*>(visitor))
    return parserVisitor->visitSimpleStmt(this);
  else
    return visitor->visitChildren(this);
}

Go2LLVMParser::SimpleStmtContext* Go2LLVMParser::simpleStmt() {
  SimpleStmtContext *_localctx = _tracker.createInstance<SimpleStmtContext>(_ctx, getState());
  enterRule(_localctx, 16, Go2LLVMParser::RuleSimpleStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(112);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(109);
      expression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(110);
      assignment();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(111);
      emptyStmt();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

Go2LLVMParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<Go2LLVMParser::ExpressionListContext *> Go2LLVMParser::AssignmentContext::expressionList() {
  return getRuleContexts<Go2LLVMParser::ExpressionListContext>();
}

Go2LLVMParser::ExpressionListContext* Go2LLVMParser::AssignmentContext::expressionList(size_t i) {
  return getRuleContext<Go2LLVMParser::ExpressionListContext>(i);
}

tree::TerminalNode* Go2LLVMParser::AssignmentContext::EQ() {
  return getToken(Go2LLVMParser::EQ, 0);
}

tree::TerminalNode* Go2LLVMParser::AssignmentContext::BINARY_OP_TOK() {
  return getToken(Go2LLVMParser::BINARY_OP_TOK, 0);
}


size_t Go2LLVMParser::AssignmentContext::getRuleIndex() const {
  return Go2LLVMParser::RuleAssignment;
}

void Go2LLVMParser::AssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignment(this);
}

void Go2LLVMParser::AssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignment(this);
}


antlrcpp::Any Go2LLVMParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Go2LLVMVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

Go2LLVMParser::AssignmentContext* Go2LLVMParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 18, Go2LLVMParser::RuleAssignment);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(114);
    expressionList();
    setState(116);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Go2LLVMParser::BINARY_OP_TOK) {
      setState(115);
      match(Go2LLVMParser::BINARY_OP_TOK);
    }
    setState(118);
    match(Go2LLVMParser::EQ);
    setState(119);
    expressionList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EmptyStmtContext ------------------------------------------------------------------

Go2LLVMParser::EmptyStmtContext::EmptyStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Go2LLVMParser::EmptyStmtContext::SEMICOLON() {
  return getToken(Go2LLVMParser::SEMICOLON, 0);
}


size_t Go2LLVMParser::EmptyStmtContext::getRuleIndex() const {
  return Go2LLVMParser::RuleEmptyStmt;
}

void Go2LLVMParser::EmptyStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEmptyStmt(this);
}

void Go2LLVMParser::EmptyStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEmptyStmt(this);
}


antlrcpp::Any Go2LLVMParser::EmptyStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Go2LLVMVisitor*>(visitor))
    return parserVisitor->visitEmptyStmt(this);
  else
    return visitor->visitChildren(this);
}

Go2LLVMParser::EmptyStmtContext* Go2LLVMParser::emptyStmt() {
  EmptyStmtContext *_localctx = _tracker.createInstance<EmptyStmtContext>(_ctx, getState());
  enterRule(_localctx, 20, Go2LLVMParser::RuleEmptyStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(121);
    match(Go2LLVMParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

Go2LLVMParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Go2LLVMParser::DeclarationContext::VAR_TOK() {
  return getToken(Go2LLVMParser::VAR_TOK, 0);
}

Go2LLVMParser::IdentifierListContext* Go2LLVMParser::DeclarationContext::identifierList() {
  return getRuleContext<Go2LLVMParser::IdentifierListContext>(0);
}

Go2LLVMParser::TypeContext* Go2LLVMParser::DeclarationContext::type() {
  return getRuleContext<Go2LLVMParser::TypeContext>(0);
}

tree::TerminalNode* Go2LLVMParser::DeclarationContext::EQ() {
  return getToken(Go2LLVMParser::EQ, 0);
}

Go2LLVMParser::ExpressionListContext* Go2LLVMParser::DeclarationContext::expressionList() {
  return getRuleContext<Go2LLVMParser::ExpressionListContext>(0);
}


size_t Go2LLVMParser::DeclarationContext::getRuleIndex() const {
  return Go2LLVMParser::RuleDeclaration;
}

void Go2LLVMParser::DeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration(this);
}

void Go2LLVMParser::DeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration(this);
}


antlrcpp::Any Go2LLVMParser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Go2LLVMVisitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

Go2LLVMParser::DeclarationContext* Go2LLVMParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 22, Go2LLVMParser::RuleDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(123);
    match(Go2LLVMParser::VAR_TOK);
    setState(124);
    identifierList();
    setState(125);
    type();
    setState(128);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Go2LLVMParser::EQ) {
      setState(126);
      match(Go2LLVMParser::EQ);
      setState(127);
      expressionList();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierListContext ------------------------------------------------------------------

Go2LLVMParser::IdentifierListContext::IdentifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> Go2LLVMParser::IdentifierListContext::IDENT_TOK() {
  return getTokens(Go2LLVMParser::IDENT_TOK);
}

tree::TerminalNode* Go2LLVMParser::IdentifierListContext::IDENT_TOK(size_t i) {
  return getToken(Go2LLVMParser::IDENT_TOK, i);
}

std::vector<tree::TerminalNode *> Go2LLVMParser::IdentifierListContext::COMMA() {
  return getTokens(Go2LLVMParser::COMMA);
}

tree::TerminalNode* Go2LLVMParser::IdentifierListContext::COMMA(size_t i) {
  return getToken(Go2LLVMParser::COMMA, i);
}


size_t Go2LLVMParser::IdentifierListContext::getRuleIndex() const {
  return Go2LLVMParser::RuleIdentifierList;
}

void Go2LLVMParser::IdentifierListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifierList(this);
}

void Go2LLVMParser::IdentifierListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifierList(this);
}


antlrcpp::Any Go2LLVMParser::IdentifierListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Go2LLVMVisitor*>(visitor))
    return parserVisitor->visitIdentifierList(this);
  else
    return visitor->visitChildren(this);
}

Go2LLVMParser::IdentifierListContext* Go2LLVMParser::identifierList() {
  IdentifierListContext *_localctx = _tracker.createInstance<IdentifierListContext>(_ctx, getState());
  enterRule(_localctx, 24, Go2LLVMParser::RuleIdentifierList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(130);
    match(Go2LLVMParser::IDENT_TOK);
    setState(135);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Go2LLVMParser::COMMA) {
      setState(131);
      match(Go2LLVMParser::COMMA);
      setState(132);
      match(Go2LLVMParser::IDENT_TOK);
      setState(137);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionListContext ------------------------------------------------------------------

Go2LLVMParser::ExpressionListContext::ExpressionListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<Go2LLVMParser::ExpressionContext *> Go2LLVMParser::ExpressionListContext::expression() {
  return getRuleContexts<Go2LLVMParser::ExpressionContext>();
}

Go2LLVMParser::ExpressionContext* Go2LLVMParser::ExpressionListContext::expression(size_t i) {
  return getRuleContext<Go2LLVMParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> Go2LLVMParser::ExpressionListContext::COMMA() {
  return getTokens(Go2LLVMParser::COMMA);
}

tree::TerminalNode* Go2LLVMParser::ExpressionListContext::COMMA(size_t i) {
  return getToken(Go2LLVMParser::COMMA, i);
}


size_t Go2LLVMParser::ExpressionListContext::getRuleIndex() const {
  return Go2LLVMParser::RuleExpressionList;
}

void Go2LLVMParser::ExpressionListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionList(this);
}

void Go2LLVMParser::ExpressionListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionList(this);
}


antlrcpp::Any Go2LLVMParser::ExpressionListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Go2LLVMVisitor*>(visitor))
    return parserVisitor->visitExpressionList(this);
  else
    return visitor->visitChildren(this);
}

Go2LLVMParser::ExpressionListContext* Go2LLVMParser::expressionList() {
  ExpressionListContext *_localctx = _tracker.createInstance<ExpressionListContext>(_ctx, getState());
  enterRule(_localctx, 26, Go2LLVMParser::RuleExpressionList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(138);
    expression(0);
    setState(143);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(139);
        match(Go2LLVMParser::COMMA);
        setState(140);
        expression(0); 
      }
      setState(145);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

Go2LLVMParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Go2LLVMParser::TypeContext::IDENT_TOK() {
  return getToken(Go2LLVMParser::IDENT_TOK, 0);
}


size_t Go2LLVMParser::TypeContext::getRuleIndex() const {
  return Go2LLVMParser::RuleType;
}

void Go2LLVMParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void Go2LLVMParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}


antlrcpp::Any Go2LLVMParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Go2LLVMVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

Go2LLVMParser::TypeContext* Go2LLVMParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 28, Go2LLVMParser::RuleType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(146);
    match(Go2LLVMParser::IDENT_TOK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

Go2LLVMParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Go2LLVMParser::UnaryExprContext* Go2LLVMParser::ExpressionContext::unaryExpr() {
  return getRuleContext<Go2LLVMParser::UnaryExprContext>(0);
}

std::vector<Go2LLVMParser::ExpressionContext *> Go2LLVMParser::ExpressionContext::expression() {
  return getRuleContexts<Go2LLVMParser::ExpressionContext>();
}

Go2LLVMParser::ExpressionContext* Go2LLVMParser::ExpressionContext::expression(size_t i) {
  return getRuleContext<Go2LLVMParser::ExpressionContext>(i);
}


size_t Go2LLVMParser::ExpressionContext::getRuleIndex() const {
  return Go2LLVMParser::RuleExpression;
}

void Go2LLVMParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void Go2LLVMParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


antlrcpp::Any Go2LLVMParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Go2LLVMVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}


Go2LLVMParser::ExpressionContext* Go2LLVMParser::expression() {
   return expression(0);
}

Go2LLVMParser::ExpressionContext* Go2LLVMParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  Go2LLVMParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  Go2LLVMParser::ExpressionContext *previousContext = _localctx;
  size_t startState = 30;
  enterRecursionRule(_localctx, 30, Go2LLVMParser::RuleExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(149);
    unaryExpr();
    _ctx->stop = _input->LT(-1);
    setState(156);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpression);
        setState(151);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(152);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << Go2LLVMParser::T__0)
          | (1ULL << Go2LLVMParser::T__1)
          | (1ULL << Go2LLVMParser::T__2)
          | (1ULL << Go2LLVMParser::T__3)
          | (1ULL << Go2LLVMParser::T__4)
          | (1ULL << Go2LLVMParser::T__5)
          | (1ULL << Go2LLVMParser::T__6)
          | (1ULL << Go2LLVMParser::T__7)
          | (1ULL << Go2LLVMParser::T__8)
          | (1ULL << Go2LLVMParser::T__9)
          | (1ULL << Go2LLVMParser::T__10)
          | (1ULL << Go2LLVMParser::T__11)
          | (1ULL << Go2LLVMParser::T__12)
          | (1ULL << Go2LLVMParser::T__13)
          | (1ULL << Go2LLVMParser::T__14)
          | (1ULL << Go2LLVMParser::T__15)
          | (1ULL << Go2LLVMParser::T__16)
          | (1ULL << Go2LLVMParser::T__17)
          | (1ULL << Go2LLVMParser::T__18))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(153);
        expression(2); 
      }
      setState(158);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- UnaryExprContext ------------------------------------------------------------------

Go2LLVMParser::UnaryExprContext::UnaryExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Go2LLVMParser::OperandContext* Go2LLVMParser::UnaryExprContext::operand() {
  return getRuleContext<Go2LLVMParser::OperandContext>(0);
}

Go2LLVMParser::UnaryExprContext* Go2LLVMParser::UnaryExprContext::unaryExpr() {
  return getRuleContext<Go2LLVMParser::UnaryExprContext>(0);
}


size_t Go2LLVMParser::UnaryExprContext::getRuleIndex() const {
  return Go2LLVMParser::RuleUnaryExpr;
}

void Go2LLVMParser::UnaryExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryExpr(this);
}

void Go2LLVMParser::UnaryExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryExpr(this);
}


antlrcpp::Any Go2LLVMParser::UnaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Go2LLVMVisitor*>(visitor))
    return parserVisitor->visitUnaryExpr(this);
  else
    return visitor->visitChildren(this);
}

Go2LLVMParser::UnaryExprContext* Go2LLVMParser::unaryExpr() {
  UnaryExprContext *_localctx = _tracker.createInstance<UnaryExprContext>(_ctx, getState());
  enterRule(_localctx, 32, Go2LLVMParser::RuleUnaryExpr);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(162);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Go2LLVMParser::STRING_TOK:
      case Go2LLVMParser::INT_TOK:
      case Go2LLVMParser::FLOAT_TOK:
      case Go2LLVMParser::IMAG_TOK:
      case Go2LLVMParser::IDENT_TOK:
      case Go2LLVMParser::PO: {
        enterOuterAlt(_localctx, 1);
        setState(159);
        operand();
        break;
      }

      case Go2LLVMParser::T__8:
      case Go2LLVMParser::T__9:
      case Go2LLVMParser::T__11:
      case Go2LLVMParser::T__12:
      case Go2LLVMParser::T__17:
      case Go2LLVMParser::T__19: {
        enterOuterAlt(_localctx, 2);
        setState(160);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << Go2LLVMParser::T__8)
          | (1ULL << Go2LLVMParser::T__9)
          | (1ULL << Go2LLVMParser::T__11)
          | (1ULL << Go2LLVMParser::T__12)
          | (1ULL << Go2LLVMParser::T__17)
          | (1ULL << Go2LLVMParser::T__19))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(161);
        unaryExpr();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperandContext ------------------------------------------------------------------

Go2LLVMParser::OperandContext::OperandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Go2LLVMParser::BasicLitContext* Go2LLVMParser::OperandContext::basicLit() {
  return getRuleContext<Go2LLVMParser::BasicLitContext>(0);
}

tree::TerminalNode* Go2LLVMParser::OperandContext::IDENT_TOK() {
  return getToken(Go2LLVMParser::IDENT_TOK, 0);
}

Go2LLVMParser::ArgumentsContext* Go2LLVMParser::OperandContext::arguments() {
  return getRuleContext<Go2LLVMParser::ArgumentsContext>(0);
}

tree::TerminalNode* Go2LLVMParser::OperandContext::PO() {
  return getToken(Go2LLVMParser::PO, 0);
}

Go2LLVMParser::ExpressionContext* Go2LLVMParser::OperandContext::expression() {
  return getRuleContext<Go2LLVMParser::ExpressionContext>(0);
}

tree::TerminalNode* Go2LLVMParser::OperandContext::PC() {
  return getToken(Go2LLVMParser::PC, 0);
}


size_t Go2LLVMParser::OperandContext::getRuleIndex() const {
  return Go2LLVMParser::RuleOperand;
}

void Go2LLVMParser::OperandContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperand(this);
}

void Go2LLVMParser::OperandContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperand(this);
}


antlrcpp::Any Go2LLVMParser::OperandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Go2LLVMVisitor*>(visitor))
    return parserVisitor->visitOperand(this);
  else
    return visitor->visitChildren(this);
}

Go2LLVMParser::OperandContext* Go2LLVMParser::operand() {
  OperandContext *_localctx = _tracker.createInstance<OperandContext>(_ctx, getState());
  enterRule(_localctx, 34, Go2LLVMParser::RuleOperand);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(172);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(164);
      basicLit();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(165);
      match(Go2LLVMParser::IDENT_TOK);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(166);
      match(Go2LLVMParser::IDENT_TOK);
      setState(167);
      arguments();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(168);
      match(Go2LLVMParser::PO);
      setState(169);
      expression(0);
      setState(170);
      match(Go2LLVMParser::PC);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentsContext ------------------------------------------------------------------

Go2LLVMParser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Go2LLVMParser::ArgumentsContext::PO() {
  return getToken(Go2LLVMParser::PO, 0);
}

tree::TerminalNode* Go2LLVMParser::ArgumentsContext::PC() {
  return getToken(Go2LLVMParser::PC, 0);
}

Go2LLVMParser::ExpressionListContext* Go2LLVMParser::ArgumentsContext::expressionList() {
  return getRuleContext<Go2LLVMParser::ExpressionListContext>(0);
}

tree::TerminalNode* Go2LLVMParser::ArgumentsContext::COMMA() {
  return getToken(Go2LLVMParser::COMMA, 0);
}


size_t Go2LLVMParser::ArgumentsContext::getRuleIndex() const {
  return Go2LLVMParser::RuleArguments;
}

void Go2LLVMParser::ArgumentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArguments(this);
}

void Go2LLVMParser::ArgumentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArguments(this);
}


antlrcpp::Any Go2LLVMParser::ArgumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Go2LLVMVisitor*>(visitor))
    return parserVisitor->visitArguments(this);
  else
    return visitor->visitChildren(this);
}

Go2LLVMParser::ArgumentsContext* Go2LLVMParser::arguments() {
  ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 36, Go2LLVMParser::RuleArguments);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(174);
    match(Go2LLVMParser::PO);
    setState(179);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << Go2LLVMParser::T__8)
      | (1ULL << Go2LLVMParser::T__9)
      | (1ULL << Go2LLVMParser::T__11)
      | (1ULL << Go2LLVMParser::T__12)
      | (1ULL << Go2LLVMParser::T__17)
      | (1ULL << Go2LLVMParser::T__19)
      | (1ULL << Go2LLVMParser::STRING_TOK)
      | (1ULL << Go2LLVMParser::INT_TOK)
      | (1ULL << Go2LLVMParser::FLOAT_TOK)
      | (1ULL << Go2LLVMParser::IMAG_TOK)
      | (1ULL << Go2LLVMParser::IDENT_TOK)
      | (1ULL << Go2LLVMParser::PO))) != 0)) {
      setState(175);
      expressionList();
      setState(177);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == Go2LLVMParser::COMMA) {
        setState(176);
        match(Go2LLVMParser::COMMA);
      }
    }
    setState(181);
    match(Go2LLVMParser::PC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BasicLitContext ------------------------------------------------------------------

Go2LLVMParser::BasicLitContext::BasicLitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Go2LLVMParser::BasicLitContext::INT_TOK() {
  return getToken(Go2LLVMParser::INT_TOK, 0);
}

tree::TerminalNode* Go2LLVMParser::BasicLitContext::FLOAT_TOK() {
  return getToken(Go2LLVMParser::FLOAT_TOK, 0);
}

tree::TerminalNode* Go2LLVMParser::BasicLitContext::IMAG_TOK() {
  return getToken(Go2LLVMParser::IMAG_TOK, 0);
}

tree::TerminalNode* Go2LLVMParser::BasicLitContext::STRING_TOK() {
  return getToken(Go2LLVMParser::STRING_TOK, 0);
}


size_t Go2LLVMParser::BasicLitContext::getRuleIndex() const {
  return Go2LLVMParser::RuleBasicLit;
}

void Go2LLVMParser::BasicLitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBasicLit(this);
}

void Go2LLVMParser::BasicLitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBasicLit(this);
}


antlrcpp::Any Go2LLVMParser::BasicLitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Go2LLVMVisitor*>(visitor))
    return parserVisitor->visitBasicLit(this);
  else
    return visitor->visitChildren(this);
}

Go2LLVMParser::BasicLitContext* Go2LLVMParser::basicLit() {
  BasicLitContext *_localctx = _tracker.createInstance<BasicLitContext>(_ctx, getState());
  enterRule(_localctx, 38, Go2LLVMParser::RuleBasicLit);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(183);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << Go2LLVMParser::STRING_TOK)
      | (1ULL << Go2LLVMParser::INT_TOK)
      | (1ULL << Go2LLVMParser::FLOAT_TOK)
      | (1ULL << Go2LLVMParser::IMAG_TOK))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDeclContext ------------------------------------------------------------------

Go2LLVMParser::FunctionDeclContext::FunctionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Go2LLVMParser::FunctionDeclContext::FUNC_TOK() {
  return getToken(Go2LLVMParser::FUNC_TOK, 0);
}

tree::TerminalNode* Go2LLVMParser::FunctionDeclContext::IDENT_TOK() {
  return getToken(Go2LLVMParser::IDENT_TOK, 0);
}

Go2LLVMParser::SignatureContext* Go2LLVMParser::FunctionDeclContext::signature() {
  return getRuleContext<Go2LLVMParser::SignatureContext>(0);
}

Go2LLVMParser::BlockContext* Go2LLVMParser::FunctionDeclContext::block() {
  return getRuleContext<Go2LLVMParser::BlockContext>(0);
}


size_t Go2LLVMParser::FunctionDeclContext::getRuleIndex() const {
  return Go2LLVMParser::RuleFunctionDecl;
}

void Go2LLVMParser::FunctionDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDecl(this);
}

void Go2LLVMParser::FunctionDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDecl(this);
}


antlrcpp::Any Go2LLVMParser::FunctionDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Go2LLVMVisitor*>(visitor))
    return parserVisitor->visitFunctionDecl(this);
  else
    return visitor->visitChildren(this);
}

Go2LLVMParser::FunctionDeclContext* Go2LLVMParser::functionDecl() {
  FunctionDeclContext *_localctx = _tracker.createInstance<FunctionDeclContext>(_ctx, getState());
  enterRule(_localctx, 40, Go2LLVMParser::RuleFunctionDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(185);
    match(Go2LLVMParser::FUNC_TOK);
    setState(186);
    match(Go2LLVMParser::IDENT_TOK);
    setState(187);
    signature();
    setState(188);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SignatureContext ------------------------------------------------------------------

Go2LLVMParser::SignatureContext::SignatureContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Go2LLVMParser::ParametersContext* Go2LLVMParser::SignatureContext::parameters() {
  return getRuleContext<Go2LLVMParser::ParametersContext>(0);
}

Go2LLVMParser::ResultContext* Go2LLVMParser::SignatureContext::result() {
  return getRuleContext<Go2LLVMParser::ResultContext>(0);
}


size_t Go2LLVMParser::SignatureContext::getRuleIndex() const {
  return Go2LLVMParser::RuleSignature;
}

void Go2LLVMParser::SignatureContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignature(this);
}

void Go2LLVMParser::SignatureContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignature(this);
}


antlrcpp::Any Go2LLVMParser::SignatureContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Go2LLVMVisitor*>(visitor))
    return parserVisitor->visitSignature(this);
  else
    return visitor->visitChildren(this);
}

Go2LLVMParser::SignatureContext* Go2LLVMParser::signature() {
  SignatureContext *_localctx = _tracker.createInstance<SignatureContext>(_ctx, getState());
  enterRule(_localctx, 42, Go2LLVMParser::RuleSignature);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(190);
    parameters();
    setState(192);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Go2LLVMParser::IDENT_TOK

    || _la == Go2LLVMParser::PO) {
      setState(191);
      result();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ResultContext ------------------------------------------------------------------

Go2LLVMParser::ResultContext::ResultContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Go2LLVMParser::ParametersContext* Go2LLVMParser::ResultContext::parameters() {
  return getRuleContext<Go2LLVMParser::ParametersContext>(0);
}

Go2LLVMParser::TypeContext* Go2LLVMParser::ResultContext::type() {
  return getRuleContext<Go2LLVMParser::TypeContext>(0);
}


size_t Go2LLVMParser::ResultContext::getRuleIndex() const {
  return Go2LLVMParser::RuleResult;
}

void Go2LLVMParser::ResultContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterResult(this);
}

void Go2LLVMParser::ResultContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitResult(this);
}


antlrcpp::Any Go2LLVMParser::ResultContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Go2LLVMVisitor*>(visitor))
    return parserVisitor->visitResult(this);
  else
    return visitor->visitChildren(this);
}

Go2LLVMParser::ResultContext* Go2LLVMParser::result() {
  ResultContext *_localctx = _tracker.createInstance<ResultContext>(_ctx, getState());
  enterRule(_localctx, 44, Go2LLVMParser::RuleResult);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(196);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Go2LLVMParser::PO: {
        enterOuterAlt(_localctx, 1);
        setState(194);
        parameters();
        break;
      }

      case Go2LLVMParser::IDENT_TOK: {
        enterOuterAlt(_localctx, 2);
        setState(195);
        type();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParametersContext ------------------------------------------------------------------

Go2LLVMParser::ParametersContext::ParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Go2LLVMParser::ParametersContext::PO() {
  return getToken(Go2LLVMParser::PO, 0);
}

tree::TerminalNode* Go2LLVMParser::ParametersContext::PC() {
  return getToken(Go2LLVMParser::PC, 0);
}

Go2LLVMParser::ParameterListContext* Go2LLVMParser::ParametersContext::parameterList() {
  return getRuleContext<Go2LLVMParser::ParameterListContext>(0);
}

tree::TerminalNode* Go2LLVMParser::ParametersContext::COMMA() {
  return getToken(Go2LLVMParser::COMMA, 0);
}


size_t Go2LLVMParser::ParametersContext::getRuleIndex() const {
  return Go2LLVMParser::RuleParameters;
}

void Go2LLVMParser::ParametersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameters(this);
}

void Go2LLVMParser::ParametersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameters(this);
}


antlrcpp::Any Go2LLVMParser::ParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Go2LLVMVisitor*>(visitor))
    return parserVisitor->visitParameters(this);
  else
    return visitor->visitChildren(this);
}

Go2LLVMParser::ParametersContext* Go2LLVMParser::parameters() {
  ParametersContext *_localctx = _tracker.createInstance<ParametersContext>(_ctx, getState());
  enterRule(_localctx, 46, Go2LLVMParser::RuleParameters);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(198);
    match(Go2LLVMParser::PO);
    setState(203);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Go2LLVMParser::IDENT_TOK) {
      setState(199);
      parameterList();
      setState(201);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == Go2LLVMParser::COMMA) {
        setState(200);
        match(Go2LLVMParser::COMMA);
      }
    }
    setState(205);
    match(Go2LLVMParser::PC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterListContext ------------------------------------------------------------------

Go2LLVMParser::ParameterListContext::ParameterListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<Go2LLVMParser::ParameterDeclContext *> Go2LLVMParser::ParameterListContext::parameterDecl() {
  return getRuleContexts<Go2LLVMParser::ParameterDeclContext>();
}

Go2LLVMParser::ParameterDeclContext* Go2LLVMParser::ParameterListContext::parameterDecl(size_t i) {
  return getRuleContext<Go2LLVMParser::ParameterDeclContext>(i);
}

std::vector<tree::TerminalNode *> Go2LLVMParser::ParameterListContext::COMMA() {
  return getTokens(Go2LLVMParser::COMMA);
}

tree::TerminalNode* Go2LLVMParser::ParameterListContext::COMMA(size_t i) {
  return getToken(Go2LLVMParser::COMMA, i);
}


size_t Go2LLVMParser::ParameterListContext::getRuleIndex() const {
  return Go2LLVMParser::RuleParameterList;
}

void Go2LLVMParser::ParameterListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterList(this);
}

void Go2LLVMParser::ParameterListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterList(this);
}


antlrcpp::Any Go2LLVMParser::ParameterListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Go2LLVMVisitor*>(visitor))
    return parserVisitor->visitParameterList(this);
  else
    return visitor->visitChildren(this);
}

Go2LLVMParser::ParameterListContext* Go2LLVMParser::parameterList() {
  ParameterListContext *_localctx = _tracker.createInstance<ParameterListContext>(_ctx, getState());
  enterRule(_localctx, 48, Go2LLVMParser::RuleParameterList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(207);
    parameterDecl();
    setState(212);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(208);
        match(Go2LLVMParser::COMMA);
        setState(209);
        parameterDecl(); 
      }
      setState(214);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterDeclContext ------------------------------------------------------------------

Go2LLVMParser::ParameterDeclContext::ParameterDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Go2LLVMParser::IdentifierListContext* Go2LLVMParser::ParameterDeclContext::identifierList() {
  return getRuleContext<Go2LLVMParser::IdentifierListContext>(0);
}

Go2LLVMParser::TypeContext* Go2LLVMParser::ParameterDeclContext::type() {
  return getRuleContext<Go2LLVMParser::TypeContext>(0);
}


size_t Go2LLVMParser::ParameterDeclContext::getRuleIndex() const {
  return Go2LLVMParser::RuleParameterDecl;
}

void Go2LLVMParser::ParameterDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterDecl(this);
}

void Go2LLVMParser::ParameterDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterDecl(this);
}


antlrcpp::Any Go2LLVMParser::ParameterDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Go2LLVMVisitor*>(visitor))
    return parserVisitor->visitParameterDecl(this);
  else
    return visitor->visitChildren(this);
}

Go2LLVMParser::ParameterDeclContext* Go2LLVMParser::parameterDecl() {
  ParameterDeclContext *_localctx = _tracker.createInstance<ParameterDeclContext>(_ctx, getState());
  enterRule(_localctx, 50, Go2LLVMParser::RuleParameterDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(215);
    identifierList();
    setState(216);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EosContext ------------------------------------------------------------------

Go2LLVMParser::EosContext::EosContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Go2LLVMParser::EosContext::SEMICOLON() {
  return getToken(Go2LLVMParser::SEMICOLON, 0);
}

tree::TerminalNode* Go2LLVMParser::EosContext::EOF() {
  return getToken(Go2LLVMParser::EOF, 0);
}


size_t Go2LLVMParser::EosContext::getRuleIndex() const {
  return Go2LLVMParser::RuleEos;
}

void Go2LLVMParser::EosContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEos(this);
}

void Go2LLVMParser::EosContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Go2LLVMListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEos(this);
}


antlrcpp::Any Go2LLVMParser::EosContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<Go2LLVMVisitor*>(visitor))
    return parserVisitor->visitEos(this);
  else
    return visitor->visitChildren(this);
}

Go2LLVMParser::EosContext* Go2LLVMParser::eos() {
  EosContext *_localctx = _tracker.createInstance<EosContext>(_ctx, getState());
  enterRule(_localctx, 52, Go2LLVMParser::RuleEos);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(218);
    _la = _input->LA(1);
    if (!(_la == Go2LLVMParser::EOF

    || _la == Go2LLVMParser::SEMICOLON)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool Go2LLVMParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 15: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool Go2LLVMParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> Go2LLVMParser::_decisionToDFA;
atn::PredictionContextCache Go2LLVMParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN Go2LLVMParser::_atn;
std::vector<uint16_t> Go2LLVMParser::_serializedATN;

std::vector<std::string> Go2LLVMParser::_ruleNames = {
  "sourceFile", "packageClause", "topLevelDecl", "block", "statementList", 
  "statement", "ifStmt", "returnStmt", "simpleStmt", "assignment", "emptyStmt", 
  "declaration", "identifierList", "expressionList", "type", "expression", 
  "unaryExpr", "operand", "arguments", "basicLit", "functionDecl", "signature", 
  "result", "parameters", "parameterList", "parameterDecl", "eos"
};

std::vector<std::string> Go2LLVMParser::_literalNames = {
  "", "'||'", "'&&'", "'=='", "'!='", "'<'", "'<='", "'>'", "'>='", "'+'", 
  "'-'", "'|'", "'^'", "'*'", "'/'", "'%'", "'<<'", "'>>'", "'&'", "'&^'", 
  "'!'", "", "", "", "", "", "", "'package'", "'var'", "'func'", "'return'", 
  "'if'", "'else'", "", "'{'", "'}'", "'('", "')'", "';'", "'='", "','"
};

std::vector<std::string> Go2LLVMParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "STRING_TOK", "INT_TOK", "FLOAT_TOK", "IMAG_TOK", "UNARY_OP_TOK", 
  "BINARY_OP_TOK", "PACKAGE_TOK", "VAR_TOK", "FUNC_TOK", "RETURN_TOK", "IF_TOK", 
  "ELSE_TOK", "IDENT_TOK", "BO", "BC", "PO", "PC", "SEMICOLON", "EQ", "COMMA", 
  "WS", "COMMENT", "LINE_COMMENT", "TERMINATOR"
};

dfa::Vocabulary Go2LLVMParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> Go2LLVMParser::_tokenNames;

Go2LLVMParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x2e, 0xdf, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 0x9, 
    0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 
    0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 0x4, 
    0x1c, 0x9, 0x1c, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 
    0x2, 0x3e, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x41, 0xb, 0x2, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x48, 0xa, 0x4, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 
    0x51, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x54, 0xb, 0x6, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x5b, 0xa, 0x7, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x61, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x68, 0xa, 0x8, 0x5, 0x8, 0x6a, 
    0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x6e, 0xa, 0x9, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x5, 0xa, 0x73, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 
    0x77, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x83, 0xa, 0xd, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0x88, 0xa, 0xe, 0xc, 0xe, 0xe, 
    0xe, 0x8b, 0xb, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0x90, 0xa, 
    0xf, 0xc, 0xf, 0xe, 0xf, 0x93, 0xb, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x7, 0x11, 
    0x9d, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0xa0, 0xb, 0x11, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x5, 0x12, 0xa5, 0xa, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 
    0xaf, 0xa, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0xb4, 0xa, 
    0x14, 0x5, 0x14, 0xb6, 0xa, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 
    0x3, 0x17, 0x5, 0x17, 0xc3, 0xa, 0x17, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 
    0xc7, 0xa, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0xcc, 0xa, 
    0x19, 0x5, 0x19, 0xce, 0xa, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 
    0x1a, 0x3, 0x1a, 0x7, 0x1a, 0xd5, 0xa, 0x1a, 0xc, 0x1a, 0xe, 0x1a, 0xd8, 
    0xb, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 
    0x1c, 0x2, 0x3, 0x20, 0x1d, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 
    0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 
    0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x2, 0x6, 0x3, 0x2, 0x3, 0x15, 
    0x6, 0x2, 0xb, 0xc, 0xe, 0xf, 0x14, 0x14, 0x16, 0x16, 0x3, 0x2, 0x17, 
    0x1a, 0x3, 0x3, 0x28, 0x28, 0x2, 0xe0, 0x2, 0x38, 0x3, 0x2, 0x2, 0x2, 
    0x4, 0x42, 0x3, 0x2, 0x2, 0x2, 0x6, 0x47, 0x3, 0x2, 0x2, 0x2, 0x8, 0x49, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x52, 0x3, 0x2, 0x2, 0x2, 0xc, 0x5a, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x10, 0x6b, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0x72, 0x3, 0x2, 0x2, 0x2, 0x14, 0x74, 0x3, 0x2, 0x2, 0x2, 
    0x16, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x18, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x1a, 
    0x84, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x94, 
    0x3, 0x2, 0x2, 0x2, 0x20, 0x96, 0x3, 0x2, 0x2, 0x2, 0x22, 0xa4, 0x3, 
    0x2, 0x2, 0x2, 0x24, 0xae, 0x3, 0x2, 0x2, 0x2, 0x26, 0xb0, 0x3, 0x2, 
    0x2, 0x2, 0x28, 0xb9, 0x3, 0x2, 0x2, 0x2, 0x2a, 0xbb, 0x3, 0x2, 0x2, 
    0x2, 0x2c, 0xc0, 0x3, 0x2, 0x2, 0x2, 0x2e, 0xc6, 0x3, 0x2, 0x2, 0x2, 
    0x30, 0xc8, 0x3, 0x2, 0x2, 0x2, 0x32, 0xd1, 0x3, 0x2, 0x2, 0x2, 0x34, 
    0xd9, 0x3, 0x2, 0x2, 0x2, 0x36, 0xdc, 0x3, 0x2, 0x2, 0x2, 0x38, 0x39, 
    0x5, 0x4, 0x3, 0x2, 0x39, 0x3f, 0x5, 0x36, 0x1c, 0x2, 0x3a, 0x3b, 0x5, 
    0x6, 0x4, 0x2, 0x3b, 0x3c, 0x5, 0x36, 0x1c, 0x2, 0x3c, 0x3e, 0x3, 0x2, 
    0x2, 0x2, 0x3d, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x41, 0x3, 0x2, 0x2, 
    0x2, 0x3f, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x40, 0x3, 0x2, 0x2, 0x2, 
    0x40, 0x3, 0x3, 0x2, 0x2, 0x2, 0x41, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x42, 
    0x43, 0x7, 0x1d, 0x2, 0x2, 0x43, 0x44, 0x7, 0x23, 0x2, 0x2, 0x44, 0x5, 
    0x3, 0x2, 0x2, 0x2, 0x45, 0x48, 0x5, 0x18, 0xd, 0x2, 0x46, 0x48, 0x5, 
    0x2a, 0x16, 0x2, 0x47, 0x45, 0x3, 0x2, 0x2, 0x2, 0x47, 0x46, 0x3, 0x2, 
    0x2, 0x2, 0x48, 0x7, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4a, 0x7, 0x24, 0x2, 
    0x2, 0x4a, 0x4b, 0x5, 0xa, 0x6, 0x2, 0x4b, 0x4c, 0x7, 0x25, 0x2, 0x2, 
    0x4c, 0x9, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4e, 0x5, 0xc, 0x7, 0x2, 0x4e, 
    0x4f, 0x5, 0x36, 0x1c, 0x2, 0x4f, 0x51, 0x3, 0x2, 0x2, 0x2, 0x50, 0x4d, 
    0x3, 0x2, 0x2, 0x2, 0x51, 0x54, 0x3, 0x2, 0x2, 0x2, 0x52, 0x50, 0x3, 
    0x2, 0x2, 0x2, 0x52, 0x53, 0x3, 0x2, 0x2, 0x2, 0x53, 0xb, 0x3, 0x2, 
    0x2, 0x2, 0x54, 0x52, 0x3, 0x2, 0x2, 0x2, 0x55, 0x5b, 0x5, 0x18, 0xd, 
    0x2, 0x56, 0x5b, 0x5, 0x12, 0xa, 0x2, 0x57, 0x5b, 0x5, 0x8, 0x5, 0x2, 
    0x58, 0x5b, 0x5, 0x10, 0x9, 0x2, 0x59, 0x5b, 0x5, 0xe, 0x8, 0x2, 0x5a, 
    0x55, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x56, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x57, 
    0x3, 0x2, 0x2, 0x2, 0x5a, 0x58, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x59, 0x3, 
    0x2, 0x2, 0x2, 0x5b, 0xd, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x60, 0x7, 0x21, 
    0x2, 0x2, 0x5d, 0x5e, 0x5, 0x12, 0xa, 0x2, 0x5e, 0x5f, 0x7, 0x28, 0x2, 
    0x2, 0x5f, 0x61, 0x3, 0x2, 0x2, 0x2, 0x60, 0x5d, 0x3, 0x2, 0x2, 0x2, 
    0x60, 0x61, 0x3, 0x2, 0x2, 0x2, 0x61, 0x62, 0x3, 0x2, 0x2, 0x2, 0x62, 
    0x63, 0x5, 0x20, 0x11, 0x2, 0x63, 0x69, 0x5, 0x8, 0x5, 0x2, 0x64, 0x67, 
    0x7, 0x22, 0x2, 0x2, 0x65, 0x68, 0x5, 0xe, 0x8, 0x2, 0x66, 0x68, 0x5, 
    0x8, 0x5, 0x2, 0x67, 0x65, 0x3, 0x2, 0x2, 0x2, 0x67, 0x66, 0x3, 0x2, 
    0x2, 0x2, 0x68, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x69, 0x64, 0x3, 0x2, 0x2, 
    0x2, 0x69, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6a, 0xf, 0x3, 0x2, 0x2, 0x2, 
    0x6b, 0x6d, 0x7, 0x20, 0x2, 0x2, 0x6c, 0x6e, 0x5, 0x1c, 0xf, 0x2, 0x6d, 
    0x6c, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x11, 
    0x3, 0x2, 0x2, 0x2, 0x6f, 0x73, 0x5, 0x20, 0x11, 0x2, 0x70, 0x73, 0x5, 
    0x14, 0xb, 0x2, 0x71, 0x73, 0x5, 0x16, 0xc, 0x2, 0x72, 0x6f, 0x3, 0x2, 
    0x2, 0x2, 0x72, 0x70, 0x3, 0x2, 0x2, 0x2, 0x72, 0x71, 0x3, 0x2, 0x2, 
    0x2, 0x73, 0x13, 0x3, 0x2, 0x2, 0x2, 0x74, 0x76, 0x5, 0x1c, 0xf, 0x2, 
    0x75, 0x77, 0x7, 0x1c, 0x2, 0x2, 0x76, 0x75, 0x3, 0x2, 0x2, 0x2, 0x76, 
    0x77, 0x3, 0x2, 0x2, 0x2, 0x77, 0x78, 0x3, 0x2, 0x2, 0x2, 0x78, 0x79, 
    0x7, 0x29, 0x2, 0x2, 0x79, 0x7a, 0x5, 0x1c, 0xf, 0x2, 0x7a, 0x15, 0x3, 
    0x2, 0x2, 0x2, 0x7b, 0x7c, 0x7, 0x28, 0x2, 0x2, 0x7c, 0x17, 0x3, 0x2, 
    0x2, 0x2, 0x7d, 0x7e, 0x7, 0x1e, 0x2, 0x2, 0x7e, 0x7f, 0x5, 0x1a, 0xe, 
    0x2, 0x7f, 0x82, 0x5, 0x1e, 0x10, 0x2, 0x80, 0x81, 0x7, 0x29, 0x2, 0x2, 
    0x81, 0x83, 0x5, 0x1c, 0xf, 0x2, 0x82, 0x80, 0x3, 0x2, 0x2, 0x2, 0x82, 
    0x83, 0x3, 0x2, 0x2, 0x2, 0x83, 0x19, 0x3, 0x2, 0x2, 0x2, 0x84, 0x89, 
    0x7, 0x23, 0x2, 0x2, 0x85, 0x86, 0x7, 0x2a, 0x2, 0x2, 0x86, 0x88, 0x7, 
    0x23, 0x2, 0x2, 0x87, 0x85, 0x3, 0x2, 0x2, 0x2, 0x88, 0x8b, 0x3, 0x2, 
    0x2, 0x2, 0x89, 0x87, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8a, 0x3, 0x2, 0x2, 
    0x2, 0x8a, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x89, 0x3, 0x2, 0x2, 0x2, 
    0x8c, 0x91, 0x5, 0x20, 0x11, 0x2, 0x8d, 0x8e, 0x7, 0x2a, 0x2, 0x2, 0x8e, 
    0x90, 0x5, 0x20, 0x11, 0x2, 0x8f, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x90, 0x93, 
    0x3, 0x2, 0x2, 0x2, 0x91, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x91, 0x92, 0x3, 
    0x2, 0x2, 0x2, 0x92, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x93, 0x91, 0x3, 0x2, 
    0x2, 0x2, 0x94, 0x95, 0x7, 0x23, 0x2, 0x2, 0x95, 0x1f, 0x3, 0x2, 0x2, 
    0x2, 0x96, 0x97, 0x8, 0x11, 0x1, 0x2, 0x97, 0x98, 0x5, 0x22, 0x12, 0x2, 
    0x98, 0x9e, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9a, 0xc, 0x3, 0x2, 0x2, 0x9a, 
    0x9b, 0x9, 0x2, 0x2, 0x2, 0x9b, 0x9d, 0x5, 0x20, 0x11, 0x4, 0x9c, 0x99, 
    0x3, 0x2, 0x2, 0x2, 0x9d, 0xa0, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9c, 0x3, 
    0x2, 0x2, 0x2, 0x9e, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x21, 0x3, 0x2, 
    0x2, 0x2, 0xa0, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa5, 0x5, 0x24, 0x13, 
    0x2, 0xa2, 0xa3, 0x9, 0x3, 0x2, 0x2, 0xa3, 0xa5, 0x5, 0x22, 0x12, 0x2, 
    0xa4, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa5, 
    0x23, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xaf, 0x5, 0x28, 0x15, 0x2, 0xa7, 0xaf, 
    0x7, 0x23, 0x2, 0x2, 0xa8, 0xa9, 0x7, 0x23, 0x2, 0x2, 0xa9, 0xaf, 0x5, 
    0x26, 0x14, 0x2, 0xaa, 0xab, 0x7, 0x26, 0x2, 0x2, 0xab, 0xac, 0x5, 0x20, 
    0x11, 0x2, 0xac, 0xad, 0x7, 0x27, 0x2, 0x2, 0xad, 0xaf, 0x3, 0x2, 0x2, 
    0x2, 0xae, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xae, 0xa7, 0x3, 0x2, 0x2, 0x2, 
    0xae, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xae, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xaf, 
    0x25, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb5, 0x7, 0x26, 0x2, 0x2, 0xb1, 0xb3, 
    0x5, 0x1c, 0xf, 0x2, 0xb2, 0xb4, 0x7, 0x2a, 0x2, 0x2, 0xb3, 0xb2, 0x3, 
    0x2, 0x2, 0x2, 0xb3, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb6, 0x3, 0x2, 
    0x2, 0x2, 0xb5, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb6, 0x3, 0x2, 0x2, 
    0x2, 0xb6, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb8, 0x7, 0x27, 0x2, 0x2, 
    0xb8, 0x27, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xba, 0x9, 0x4, 0x2, 0x2, 0xba, 
    0x29, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xbc, 0x7, 0x1f, 0x2, 0x2, 0xbc, 0xbd, 
    0x7, 0x23, 0x2, 0x2, 0xbd, 0xbe, 0x5, 0x2c, 0x17, 0x2, 0xbe, 0xbf, 0x5, 
    0x8, 0x5, 0x2, 0xbf, 0x2b, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xc2, 0x5, 0x30, 
    0x19, 0x2, 0xc1, 0xc3, 0x5, 0x2e, 0x18, 0x2, 0xc2, 0xc1, 0x3, 0x2, 0x2, 
    0x2, 0xc2, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc3, 0x2d, 0x3, 0x2, 0x2, 0x2, 
    0xc4, 0xc7, 0x5, 0x30, 0x19, 0x2, 0xc5, 0xc7, 0x5, 0x1e, 0x10, 0x2, 
    0xc6, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc7, 
    0x2f, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xcd, 0x7, 0x26, 0x2, 0x2, 0xc9, 0xcb, 
    0x5, 0x32, 0x1a, 0x2, 0xca, 0xcc, 0x7, 0x2a, 0x2, 0x2, 0xcb, 0xca, 0x3, 
    0x2, 0x2, 0x2, 0xcb, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xce, 0x3, 0x2, 
    0x2, 0x2, 0xcd, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xce, 0x3, 0x2, 0x2, 
    0x2, 0xce, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xd0, 0x7, 0x27, 0x2, 0x2, 
    0xd0, 0x31, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd6, 0x5, 0x34, 0x1b, 0x2, 0xd2, 
    0xd3, 0x7, 0x2a, 0x2, 0x2, 0xd3, 0xd5, 0x5, 0x34, 0x1b, 0x2, 0xd4, 0xd2, 
    0x3, 0x2, 0x2, 0x2, 0xd5, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd4, 0x3, 
    0x2, 0x2, 0x2, 0xd6, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xd7, 0x33, 0x3, 0x2, 
    0x2, 0x2, 0xd8, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xda, 0x5, 0x1a, 0xe, 
    0x2, 0xda, 0xdb, 0x5, 0x1e, 0x10, 0x2, 0xdb, 0x35, 0x3, 0x2, 0x2, 0x2, 
    0xdc, 0xdd, 0x9, 0x5, 0x2, 0x2, 0xdd, 0x37, 0x3, 0x2, 0x2, 0x2, 0x19, 
    0x3f, 0x47, 0x52, 0x5a, 0x60, 0x67, 0x69, 0x6d, 0x72, 0x76, 0x82, 0x89, 
    0x91, 0x9e, 0xa4, 0xae, 0xb3, 0xb5, 0xc2, 0xc6, 0xcb, 0xcd, 0xd6, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

Go2LLVMParser::Initializer Go2LLVMParser::_init;
