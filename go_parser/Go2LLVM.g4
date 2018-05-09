grammar Go2LLVM;

// for EOS in cpp
@parser::members {
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
          // We're only interested in tokens on the HIDDEN channel.
          return false;
      }

      if (ahead->getType() == TERMINATOR) {
          // There is definitely a line terminator ahead.
          return true;
      }

      if (ahead->getType() == WS) {
          // Get the token ahead of the current whitespaces.
          possibleIndexEosToken = this->getCurrentToken()->getTokenIndex() - 2;
          ahead = _input->get(possibleIndexEosToken);
      }

      // Get the token's text and type.
      std::string text = ahead->getText();
      size_t type = ahead->getType();

      // Check if the token is, or contains a line terminator.
      return (type == COMMENT && (text.find("\r") != std::string::npos || text.find("\n") != std::string::npos)) ||
              (type == TERMINATOR);
    }
}

// for EOS in java
//@parser::members {
//    /**
//     * Returns {@code true} iff on the current index of the parser's
//     * token stream a token exists on the {@code HIDDEN} channel which
//     * either is a line terminator, or is a multi line comment that
//     * contains a line terminator.
//     *
//     * @return {@code true} iff on the current index of the parser's
//     * token stream a token exists on the {@code HIDDEN} channel which
//     * either is a line terminator, or is a multi line comment that
//     * contains a line terminator.
//     */
//    private boolean lineTerminatorAhead() {
//        // Get the token ahead of the current index.
//        int possibleIndexEosToken = this.getCurrentToken().getTokenIndex() - 1;
//        Token ahead = _input.get(possibleIndexEosToken);
//        if (ahead.getChannel() != Lexer.HIDDEN) {
//            // We're only interested in tokens on the HIDDEN channel.
//            return false;
//        }
//
//        if (ahead.getType() == TERMINATOR) {
//            // There is definitely a line terminator ahead.
//            return true;
//        }
//
//        if (ahead.getType() == WS) {
//            // Get the token ahead of the current whitespaces.
//            possibleIndexEosToken = this.getCurrentToken().getTokenIndex() - 2;
//            ahead = _input.get(possibleIndexEosToken);
//        }
//
//        // Get the token's text and type.
//        String text = ahead.getText();
//        int type = ahead.getType();
//
//        // Check if the token is, or contains a line terminator.
//        return (type == COMMENT && (text.contains("\r") || text.contains("\n"))) ||
//                (type == TERMINATOR);
//    }
//}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PARSER

// top level stuff
//SourceFile = PackageClause Eos { TopLevelDecl Eos }
sourceFile
    : packageClause eos (topLevelDecl eos)*
    ;

//PackageClause = "package" ident_tok
packageClause
    : PACKAGE_TOK IDENT_TOK
    ;

//TopLevelDecl = Declaration | FunctionDecl
topLevelDecl
    : declaration
    | functionDecl
    ;

//Block = "{" StatementList "}"
block
    : BO statementList BC
    ;

// Statements
//StatementList = { Statement EOS }
statementList
    : ( statement eos )*
    ;

//Statement = Declaration | SimpleStmt | Block | ReturnStmt | IfStmt
statement
    : declaration
    | simpleStmt
    | block
    | returnStmt
    | ifStmt
    ;

//IfStmt = 'if' [SimpleStmt ';'] Expression Block ['else' (IfStmt | Block)]
ifStmt
    : IF_TOK (simpleStmt SEMICOLON)? expression block ( ELSE_TOK ( ifStmt | block ) )?
    ;

//ReturnStmt = "return" [ExpressionList]
returnStmt
    : RETURN_TOK expressionList?
    ;

//SimpleStmt = EmptyStmt | Expression | Assignment
simpleStmt
    : expression
    | assignment
    | emptyStmt
    ;

//Assignment = expressionList [binary_op_tok] '=' expressionList
assignment
    : expressionList ( BINARY_OP_TOK )? EQ expressionList
    ;

//EmptyStmt = ";"
emptyStmt
    : SEMICOLON
    ;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// declarations
//Declaration = "var" IdentifierList Type ["=" ExpressionList]
declaration
    : VAR_TOK identifierList type ( EQ expressionList )?
    ;

//IdentifierList = identifier { "," identifier }
identifierList
    : IDENT_TOK ( COMMA IDENT_TOK )*
    ;

//ExpressionList = Expression { "," Expression }
expressionList
    : expression ( COMMA expression )*
    ;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// types
//Type = IDENT_TOK
type
    : IDENT_TOK
    ;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Expressions
//Expression = UnaryExpr | Expression binary_op_tok Expression
expression
    : unaryExpr
    | expression ('||' | '&&' | '==' | '!=' | '<' | '<=' | '>' | '>=' | '+' | '-' | '|' | '^' | '*' | '/' | '%' | '<<' | '>>' | '&' | '&^') expression
    ;

//UnaryExpr = unary_op_tok UnaryExpr | operand
unaryExpr
    : operand
    | ('+'|'-'|'!'|'^'|'*'|'&') unaryExpr
    ;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Operands
//Operand = basicLit | ident_tok | ident_tok Arguments | "(" Expression ")" .
operand
    : basicLit
    | IDENT_TOK
    | IDENT_TOK arguments
    | PO expression PC
    ;

//Arguments '(' [ExpressionList [',']] ')'
arguments
    : PO ( expressionList COMMA? )? PC
    ;

//BasicLit = int_tok | float_tok | imag_tok  | string_tok
basicLit
    : INT_TOK
    | FLOAT_TOK
    | IMAG_TOK
    | STRING_TOK
    ;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Functions
//Function = func_tok ident_tok signature block
functionDecl
    : FUNC_TOK IDENT_TOK signature block
    ;

//Signature = parameters [result]
signature
    : parameters result?
    ;

//Result = parameters | type
result
    : parameters
    | type
    ;

//Parameters = '(' [parameterList [',']] ')'
parameters
    : PO ( parameterList COMMA? )? PC
    ;

//ParameterList = parameterDecl { COMMA parameterDecl }
parameterList
    : parameterDecl ( COMMA parameterDecl )*
    ;

//ParameterDecl = identifielList type
parameterDecl
    : identifierList type
    ;

// EOS
eos
    : SEMICOLON
    | EOF
    | {lineTerminatorAhead()}?
    ;




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// LEXER

//string_tok = '"' {'\' ('"' | '\') | OCTAL_BYTE_VALUE | HEX_BYTE_VALUE | ~('"' | '\')} '"'
STRING_TOK
    : '"' ('\\' ["\\] | BYTE_VALUE | ~["\\])* '"'
    ;

fragment LETTER
    : [a-zA-Z]
    | '_'
    ;

fragment BYTE_VALUE
    : OCTAL_BYTE_VALUE | HEX_BYTE_VALUE
    ;

fragment OCTAL_BYTE_VALUE
    : '\\' OCTAL_DIGIT OCTAL_DIGIT OCTAL_DIGIT
    ;

fragment HEX_BYTE_VALUE
    : '\\' 'x' HEX_DIGIT HEX_DIGIT
    ;


//int_tok = (1..9) {(1..9)} | 0 {(0..7)} | 0 (x | X) {(0..9 | a..f | A..F)}
INT_TOK
    : DECIMAL_LIT
    | OCTAL_LIT
    | HEX_LIT
    ;

fragment DECIMAL_LIT
    : [1-9] DECIMAL_DIGIT*
    ;

fragment OCTAL_LIT
    : '0' OCTAL_DIGIT*
    ;

fragment HEX_LIT
    : '0' ( 'x' | 'X' ) HEX_DIGIT+
    ;

fragment DECIMAL_DIGIT
    : [0-9]
    ;

fragment DECIMALS
    : DECIMAL_DIGIT+
    ;

fragment OCTAL_DIGIT
    : [0-7]
    ;

fragment HEX_DIGIT
    : [0-9a-fA-F]
    ;


//float_tok = (1..9) {(1..9)} '.' [(1..9) {(1..9)}] [('e' | 'E') [('+' | '-')] (1..9) {(1..9)}]
FLOAT_TOK
    : DECIMALS '.' DECIMALS? EXPONENT?
    | DECIMALS EXPONENT
    | '.' DECIMALS EXPONENT?
    ;

fragment EXPONENT
    : ( 'e' | 'E' ) ( '+' | '-' )? DECIMALS
    ;

//imag_tok = ((1..9) {(1..9)} | float_tok) 'i'
IMAG_TOK
    : (DECIMALS | FLOAT_TOK) 'i'
    ;


//unary_op_tok = ('+' | '-' | '!' | '^' | '*' | '&')
UNARY_OP_TOK
    : '+'
    | '-'
    | '!'
    | '^'
    | '*'
    | '&'
    ;

//binary_op_tok = ('||' | '&&' | '==' | '!=' | '<' | '<=' | '>' | '>=' | '+' | '-' | '|' | '^'' | '*' | '/' | '%' | '<<' | '>>' | '&' | '&^')
BINARY_OP_TOK
    : '||' | '&&' | REL_OP | '|' | MUL_OP | UNARY_OP_TOK
    ;

fragment REL_OP
    : '=='
    | '!='
    | '<'
    | '<='
    | '>'
    | '>='
    ;

fragment MUL_OP
    : '/'
    | '%'
    | '<<'
    | '>>'
    | '&^'
    ;


//keywords
PACKAGE_TOK
    : 'package'
    ;
VAR_TOK
    : 'var'
    ;
FUNC_TOK
    : 'func'
    ;
RETURN_TOK
    : 'return'
    ;
IF_TOK
    : 'if'
    ;
ELSE_TOK
    : 'else'
    ;

//ident_tok = (a..z | _) {(a..z | _) | (0..9)}
IDENT_TOK
    : LETTER ( LETTER | DECIMAL_DIGIT )*
    ;

// Whitespace and comments
BO  : '{' ;
BC  : '}' ;
PO  : '(' ;
PC  : ')' ;
SEMICOLON : ';' ;
EQ  : '=' ;
COMMA : ',' ;

WS  :  [ \t]+ -> channel(HIDDEN)
    ;

COMMENT
    : '/*' .*? '*/' -> channel(HIDDEN)
    ;

LINE_COMMENT
    : '//' ~[\r\n]* -> channel(HIDDEN)
    ;

TERMINATOR
	: [\r\n]+ -> channel(HIDDEN)
	;

