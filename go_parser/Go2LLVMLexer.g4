lexer grammar Go2LLVMLexer;

// String
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


// Integer number
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


// Float number
FLOAT_TOK
    : DECIMALS '.' DECIMALS? EXPONENT?
    | DECIMALS EXPONENT
    | '.' DECIMALS EXPONENT?
    ;

fragment EXPONENT
    : ( 'e' | 'E' ) ( '+' | '-' )? DECIMALS
    ;

// Imaginary number
IMAG_TOK
    : (DECIMALS | FLOAT_TOK) 'i'
    ;

// Operators
UNARY_OP_TOK
    : '+'
    | '-'
    | '!'
    | '^'
    | '*'
    | '&'
    ;

BINARY_OP_TOK
    : '||' | '&&' | REL_OP | ADD_OP | MUL_OP
    ;

fragment REL_OP
    : '=='
    | '!='
    | '<'
    | '<='
    | '>'
    | '>='
    ;

fragment ADD_OP
    : '+'
    | '-'
    | '|'
    | '^'
    ;

fragment MUL_OP
    : '*'
    | '/'
    | '%'
    | '<<'
    | '>>'
    | '&'
    | '&^'
    ;


// Keywords
PACKAGE_TOK
    : 'package'
    ;
TYPE_TOK
    : 'type'
    ;

VAR_TOK
    : 'var'
    ;
FUNC_TOK
    : 'func'
    ;
FOR_TOK
    : 'for'
    ;
BREAK_TOK
    : 'break'
    ;
CONTINUE_TOK
    : 'continue'
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

// Identifier
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

