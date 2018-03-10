/*
// tokens from https://golang.org/src/go/token/token.go

// Legend
L - [a-zA-Z]
l - [a-z]
c - [0-9]
{} - 0 or more times
[] - 0 or 1 time
| - or
* - anything

// Identifiers and basic type literals
// (these tokens stand for classes of literals)
IDENT_TOK  | L{L|c}
INT_TOK    | c{c}
FLOAT_TOK  | c{c}.c{c}
IMAG_TOK   | c{c}i | c{c}.c{c}i
CHAR_TOK   | 'L{L|c}'
STRING_TOK | "L{L|c}"

// Operators and delimiters
ADD_TOK | +
SUB_TOK | -
MUL_TOK | *
QUO_TOK | /
REM_TOK | %

LPAREN_TOK | (
LBRACK_TOK | [
LBRACE_TOK | {
COMMA _TOK | ,
PERIOD_TOK | .

RPAREN_TOK    | )
RBRACK_TOK    | ]
RBRACE_TOK    | }
SEMICOLON_TOK | ;
COLON_TOK     | :


// Keywords
ERROR_TOK       | ERROR
EOF_TOK         | EOF
COMMENT_TOK     | //{*}

BREAK_TOK       | break
CASE_TOK        | case
CHAN_TOK        | CHAN
CONST_TOK       | const
CONTINUE_TOK    | continue

DEFAULT_TOK     | default
DEFER_TOK       | defer
ELSE_TOK        | else
FALLTHROUGH_TOK | fallthrough
FOR_TOK         | for

FUNC_TOK        | func
GO_TOK          | go
GOTO_TOK        | goto
IF_TOK          | if
IMPORT_TOK      | import

INTERFACE_TOK   | interface
MAP_TOK         | map
PACKAGE_TOK     | package
RANGE_TOK       | range
RETURN_TOK      | return

SELECT_TOK      | select
STRUCT_TOK      | struct
SWITCH_TOK      | switch
TYPE_TOK        | type
VAR_TOK         | var



AND     // &
OR      // |
XOR     // ^
SHL     // <<
SHR     // >>
AND_NOT // &^

ADD_ASSIGN // +=
SUB_ASSIGN // -=
MUL_ASSIGN // *=
QUO_ASSIGN // /=
REM_ASSIGN // %=

AND_ASSIGN     // &=
OR_ASSIGN      // |=
XOR_ASSIGN     // ^=
SHL_ASSIGN     // <<=
SHR_ASSIGN     // >>=
AND_NOT_ASSIGN // &^=

LAND  // &&
LOR   // ||
ARROW // <-
INC   // ++
DEC   // --

EQL    // ==
LSS    // <
GTR    // >
ASSIGN // =
NOT    // !

NEQ      // !=
LEQ      // <=
GEQ      // >=
DEFINE   // :=
ELLIPSIS // ...

*/

enum token_id {
    comment_tok,
    ident_tok, int_tok, float_tok, imag_tok, char_tok, string_tok};

typedef struct {
    enum token_id id;
    char* value;
} token;

struct StateFunc {
    struct StateFunc (*func)();
};


/* States */
struct StateFunc state_identificator();
struct StateFunc state_keyword();
struct StateFunc state_number();
struct StateFunc state_operator();
struct StateFunc state_string();
