#include "helpers.c"


/* Legend
L - [a-zA-Z_]
l - [a-z_]
c - [0-9]
h - [0-9a-f]
{} - 0 or more times
[] - 0 or 1 time
| - or
* - anything
*/

enum token_id {
    // Identifiers and basic type literals
    // (these tokens stand for classes of literals)
    IDENT_TOK,  /* | L{L|c} */
    INT_TOK,    /* | c{c} */
    FLOAT_TOK,  /* | c{c}.c{c} */
    IMAG_TOK,   /* | c{c}i | c{c}.c{c}i */
    CHAR_TOK,   /* | 'L{L|c}' */
    STRING_TOK, /* | "L{L|c}" */

    // Special
    ERROR_TOK,       /* | ERROR */
    EOF_TOK,         /* | EOF */
    COMMENT_TOK,     /* | //{*} |, /*{*}*/

    // Operators and delimiters
    ADD_TOK,         /* | + */
    INC_TOK,         /* | ++ */
    ADD_ASSIGN_TOK,  /* | += */

    SUB_TOK,         /* | - */
    DEC_TOK,         /* | -- */
    SUB_ASSIGN_TOK,  /* | -= */

    MUL_TOK,         /* | * */
    MUL_ASSIGN_TOK,  /* | *= */

    QUO_TOK,         /* | / */
    QUO_ASSIGN_TOK,  /* | /= */

    REM_TOK,         /* | % */
    REM_ASSIGN_TOK,  /* | %= */

    AND_TOK,             /* | & */
    AND_NOT_TOK,         /* | &^ */
    AND_NOT_ASSIGN_TOK,  /* | &^= */
    LAND_TOK,            /* | && */
    AND_ASSIGN_TOK,      /* | &= */

    OR_TOK,          /* | | */
    OR_ASSIGN_TOK,   /* | |= */
    LOR_TOK,         /* | || */

    XOR_TOK,         /* | ^ */
    XOR_ASSIGN_TOK,  /* | ^= */

    LSS_TOK,         /* | < */
    ARROW_TOK,       /* | <- */
    SHL_TOK,         /* | << */
    LEQ_TOK,         /* | <= */
    SHL_ASSIGN_TOK,  /* | <<= */

    GTR_TOK,         /* | > */
    GEQ_TOK,         /* | >= */
    SHR_TOK,         /* | >> */
    SHR_ASSIGN_TOK,  /* | >>= */

    ASSIGN_TOK,      /* | = */
    EQL_TOK,         /* | == */

    PERIOD_TOK,      /* | . */
    ELLIPSIS_TOK,    /* | ... */

    LPAREN_TOK,  /* | ( */
    LBRACK_TOK,  /* | [ */
    LBRACE_TOK,  /* | { */
    COMMA_TOK,   /* | , */

    RPAREN_TOK,    /* | ) */
    RBRACK_TOK,    /* | ] */
    RBRACE_TOK,    /* | } */
    SEMICOLON_TOK, /* | ;  */

    COLON_TOK,       /* | : */
    DEFINE_TOK,      /* | := */

    NOT_TOK,         /* | ! */
    NEQ_TOK,         /* | != */

    // Keywords
    BREAK_TOK,       /* | break */
    CASE_TOK,        /* | case */
    CHAN_TOK,        /* | chan */
    CONST_TOK,       /* | const */
    CONTINUE_TOK,    /* | continue */

    DEFAULT_TOK,     /* | default */
    DEFER_TOK,       /* | defer */
    ELSE_TOK,        /* | else */
    FALLTHROUGH_TOK, /* | fallthrough */
    FOR_TOK,         /* | for */

    FUNC_TOK,        /* | func */
    GO_TOK,          /* | go */
    GOTO_TOK,        /* | goto */
    IF_TOK,          /* | if */
    IMPORT_TOK,      /* | import */

    INTERFACE_TOK,   /* | interface */
    MAP_TOK,         /* | map */
    PACKAGE_TOK,     /* | package */
    RANGE_TOK,       /* | range */
    RETURN_TOK,      /* | return */

    SELECT_TOK,      /* | select */
    STRUCT_TOK,      /* | struct */
    SWITCH_TOK,      /* | switch */
    TYPE_TOK,        /* | type */
    VAR_TOK          /* | var */
};

typedef struct {
    char *key;
    enum token_id value;
} keyword;

const char keyword_list_size = 25;
const keyword keyword_list[keyword_list_size] = {
    {"break", BREAK_TOK},
    {"default", DEFAULT_TOK},
    {"func", FUNC_TOK},
    {"interface", INTERFACE_TOK},
    {"select", SELECT_TOK},
    {"case", CASE_TOK},
    {"defer", DEFER_TOK},
    {"go", GO_TOK},
    {"map", MAP_TOK},
    {"struct", STRUCT_TOK},
    {"chan", CHAN_TOK},
    {"else", ELSE_TOK},
    {"goto", GOTO_TOK},
    {"package", PACKAGE_TOK},
    {"switch", SWITCH_TOK},
    {"const", CONST_TOK},
    {"fallthrough", FALLTHROUGH_TOK},
    {"if", IF_TOK},
    {"range", RANGE_TOK},
    {"type", TYPE_TOK},
    {"continue", CONTINUE_TOK},
    {"for", FOR_TOK},
    {"import", IMPORT_TOK},
    {"return", RETURN_TOK},
    {"var", VAR_TOK}
}

typedef struct {
    enum token_id id;
    vector vec;
} token;

typedef struct {
    char current_char;
    FILE *input_stream;
    token tok;
} context;

struct state {
    struct state (*func)(context *ctx);
};


/* States */
struct state s_identificator(context* ctx);
struct state s_keyword(context* ctx);
struct state s_number(context* ctx);
struct state s_operator(context* ctx);
struct state s_string(context* ctx);
struct state s_char(context* ctx);
struct state s_eot(context* ctx);
struct state s_error(context* ctx);
struct state s_comment(context* ctx);
