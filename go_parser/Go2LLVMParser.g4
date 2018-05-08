parser grammar Go2LLVMParser;

options { tokenVocab=Go2LLVMLexer; }

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
    | function
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
//Expression = UnaryExpr | Expression binary_op Expression .
expression
    : unaryExpr
    | expression BINARY_OP_TOK expression
    ;

//UnaryExpr = PrimaryExpr | unary_op_tok UnaryExpr .
unaryExpr
    : operand
    | UNARY_OP_TOK unaryExpr
    ;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Operands
//Operand = basicLit | IDENT_TOK | "(" Expression ")" .
operand
    : basicLit
    | IDENT_TOK
    | PO expression PC
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
//Function = FUNC_TOK signature block
function
    : FUNC_TOK signature block
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

//Parameters = '(' ( parameterList )? ')'
parameters
    : PO ( parameterList COMMA? )? PC
    ;

//ParameterList = parameterDecl { COMMA parameterDecl }
parameterList
    : parameterDecl ( COMMA parameterDecl )*
    ;

//ParameterDecl = identifielList? type
parameterDecl
    : identifierList? type
    ;

// EOS
eos
    : SEMICOLON
    | EOF
    ;