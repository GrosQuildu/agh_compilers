
// Generated from /home/gros/studia/eaiib_3b/kompilatory/go_parser/Go2LLVM.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"


namespace go_parser {


class  Go2LLVMLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, STRING_TOK = 22, BOOL_TOK = 23, INT_TOK = 24, FLOAT_TOK = 25, 
    IMAG_TOK = 26, UNARY_OP_TOK = 27, BINARY_OP_TOK = 28, PACKAGE_TOK = 29, 
    VAR_TOK = 30, FUNC_TOK = 31, RETURN_TOK = 32, IF_TOK = 33, ELSE_TOK = 34, 
    IDENT_TOK = 35, BO = 36, BC = 37, PO = 38, PC = 39, SEMICOLON = 40, 
    EQ = 41, COMMA = 42, WS = 43, COMMENT = 44, LINE_COMMENT = 45, TERMINATOR = 46
  };

  Go2LLVMLexer(antlr4::CharStream *input);
  ~Go2LLVMLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace go_parser
