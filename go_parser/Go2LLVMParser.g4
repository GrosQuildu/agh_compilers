parser grammar Go2LLVMParser;

options { tokenVocab=Go2LLVMLexer; }

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
// top level stuff
//SourceFile       = PackageClause ";" { TopLevelDecl ";" } .
sourceFile
    : packageClause eos (topLevelDecl eos)*
    ;

//PackageClause  = "package" PackageName .
packageClause
    : PACKAGE_TOK IDENT_TOK
    ;

//TopLevelDecl  = Declaration | FunctionDecl .
topLevelDecl
    : declaration
    | functionDecl
    ;

//Block = "{" StatementList "}" .
block
    : BO statementList BC
    ;

//StatementList = { Statement ";" } .
statementList
    : ( statement eos )*
    ;

statement
    : declaration
    | simpleStmt
    | block
    | returnStmt
    | ifStmt
    ;

//IfStmt = 'if' [ SimpleStmt ';' ] Expression Block [ 'else' (IfStmt | Block) ]
ifStmt
    : IF_TOK (simpleStmt SEMICOLON)? expression block ( ELSE_TOK ( ifStmt | block ) )?
    ;

//ReturnStmt = "return" [ ExpressionList ] .
returnStmt
    : RETURN_TOK expressionList?
    ;


//SimpleStmt = EmptyStmt | ExpressionStmt | SendStmt | IncDecStmt | Assignment | ShortVarDecl .
simpleStmt
    : expression
    | assignment
    | emptyStmt
    ;

//Assignment = expressionList (BINARY_OP)? '=' expressionList
assignment
    : expressionList ( BINARY_OP_TOK )? EQ expressionList
    ;

emptyStmt
    : SEMICOLON
    ;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// declarations
//Declaration = "var" IdentifierList Type ( "=" ExpressionList )? .
declaration
    : VAR_TOK identifierList type ( EQ expressionList )?
    ;

//IdentifierList = identifier { "," identifier } .
identifierList
    : IDENT_TOK ( COMMA IDENT_TOK )*
    ;

//ExpressionList = Expression { "," Expression } .
expressionList
    : expression ( COMMA expression )*
    ;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// types
//Type = IDENT_TOK .
type
    : IDENT_TOK
    ;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Expressions
//Expression = UnaryExpr | Expression binary_op Expression | '(' Expression ')'.
expression
    : unaryExpr
    | expression BINARY_OP_TOK expression
    | PO expression PC
    ;

//UnaryExpr = PrimaryExpr | unary_op_tok UnaryExpr .
unaryExpr
    : UNARY_OP_TOK unaryExpr
    | operand
    ;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Operands
//Operand = basicLit | IDENT_TOK | "(" Expression ")" .
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

//BasicLit = int_tok | float_tok | imag_tok  | string_tok .
basicLit
    : INT_TOK
    | FLOAT_TOK
    | IMAG_TOK
    | STRING_TOK
    ;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Functions
//Function = FUNC_TOK identifier signature block
functionDecl
    : FUNC_TOK IDENT_TOK signature block
    ;

//Signature = parameters ( result )?
signature
    : parameters result?
    ;

//Result = parameters | type
result
    : parameters
    | type
    ;

//Parameters = '(' ( parameterList ','? )? ')'
parameters
    : PO ( parameterList COMMA? )? PC
    ;

//ParameterList = parameterDecl { COMMA parameterDecl }
parameterList
    : parameterDecl ( COMMA parameterDecl )*
    ;

//ParameterDecl = identifielList? type
parameterDecl
    : identifierList type
    ;

// EOS
eos
    : SEMICOLON
    | EOF
//    | {lineTerminatorAhead()}?
    ;