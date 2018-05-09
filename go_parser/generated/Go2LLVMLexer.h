
// Generated from /home/gros/studia/eaiib_3b/kompilatory/go_parser/Go2LLVMLexer.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"


namespace go_parser {


class  Go2LLVMLexer : public antlr4::Lexer {
public:
  enum {
    STRING_TOK = 1, INT_TOK = 2, FLOAT_TOK = 3, IMAG_TOK = 4, BINARY_OP_TOK = 5, 
    UNARY_OP_TOK = 6, PACKAGE_TOK = 7, VAR_TOK = 8, FUNC_TOK = 9, RETURN_TOK = 10, 
    IF_TOK = 11, ELSE_TOK = 12, IDENT_TOK = 13, BO = 14, BC = 15, PO = 16, 
    PC = 17, SEMICOLON = 18, EQ = 19, COMMA = 20, WS = 21, COMMENT = 22, 
    LINE_COMMENT = 23, TERMINATOR = 24
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
