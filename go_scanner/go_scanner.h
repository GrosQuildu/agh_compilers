#ifndef GO_SCANER_H
#define GO_SCANER_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/file.h>

#include "helpers.h"


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

#define FOREACH_TOK(TOK,TOKEND) \
    /* Identifiers and basic type literals */ \
    /* (these tokens stand for classes of literals) */ \
    TOK(IDENT_TOK)  /* | L{L|c} */ \
    TOK(INT_TOK)    /* | c{c} */ \
    TOK(FLOAT_TOK)  /* | c{c}[.]{c} */ \
    TOK(IMAG_TOK)   /* | c{c}i | c{c}[.]{c}i */ \
    TOK(CHAR_TOK)   /* | 'L{L|c}' */ \
    TOK(STRING_TOK) /* | "L{L|c}" */ \
    \
    /* Special */ \
    TOK(ERROR_TOK)       /* | ERROR */ \
    TOK(EOF_TOK)         /* | EOF */ \
    TOK(COMMENT_TOK)     /* | //{*} | /start*start/ */ \
    TOK(WHITESPACE_TOK)  /* | whitespaces */ \
    \
    /* Operators and delimiters */ \
    TOK(ADD_TOK)         /* | + */ \
    TOK(INC_TOK)         /* | ++ */ \
    TOK(ADD_ASSIGN_TOK)  /* | += */ \
    \
    TOK(SUB_TOK)         /* | - */ \
    TOK(DEC_TOK)         /* | -- */ \
    TOK(SUB_ASSIGN_TOK)  /* | -= */ \
    \
    TOK(MUL_TOK)         /* | * */ \
    TOK(MUL_ASSIGN_TOK)  /* | *= */ \
    \
    TOK(QUO_TOK)         /* | / */ \
    TOK(QUO_ASSIGN_TOK)  /* | /= */ \
    \
    TOK(REM_TOK)         /* | % */ \
    TOK(REM_ASSIGN_TOK)  /* | %= */ \
    \
    TOK(AND_TOK)             /* | & */ \
    TOK(AND_NOT_TOK)         /* | &^ */ \
    TOK(AND_NOT_ASSIGN_TOK)  /* | &^= */ \
    TOK(LAND_TOK)            /* | && */ \
    TOK(AND_ASSIGN_TOK)      /* | &= */ \
    \
    TOK(OR_TOK)          /* | | */ \
    TOK(OR_ASSIGN_TOK)   /* | |= */ \
    TOK(LOR_TOK)         /* | || */ \
    \
    TOK(XOR_TOK)         /* | ^ */ \
    TOK(XOR_ASSIGN_TOK)  /* | ^= */ \
    \
    TOK(LSS_TOK)         /* | < */ \
    TOK(ARROW_TOK)       /* | <- */ \
    TOK(SHL_TOK)         /* | << */ \
    TOK(LEQ_TOK)         /* | <= */ \
    TOK(SHL_ASSIGN_TOK)  /* | <<= */ \
    \
    TOK(GTR_TOK)         /* | > */ \
    TOK(GEQ_TOK)         /* | >= */ \
    TOK(SHR_TOK)         /* | >> */ \
    TOK(SHR_ASSIGN_TOK)  /* | >>= */ \
    \
    TOK(ASSIGN_TOK)      /* | = */ \
    TOK(EQL_TOK)         /* | == */ \
    \
    TOK(PERIOD_TOK)      /* | . */ \
    TOK(ELLIPSIS_TOK)    /* | ... */ \
    \
    TOK(LPAREN_TOK)  /* | ( */ \
    TOK(LBRACK_TOK)  /* | [ */ \
    TOK(LBRACE_TOK)  /* | { */ \
    TOK(COMMA_TOK)   /* | , */ \
    \
    TOK(RPAREN_TOK)    /* | ) */ \
    TOK(RBRACK_TOK)    /* | ] */ \
    TOK(RBRACE_TOK)    /* | } */ \
    TOK(SEMICOLON_TOK) /* | ;  */ \
    \
    TOK(COLON_TOK)       /* | : */ \
    TOK(DEFINE_TOK)      /* | := */ \
    \
    TOK(NOT_TOK)         /* | ! */ \
    TOK(NEQ_TOK)         /* | != */ \
    \
    /* Keywords */ \
    TOK(BREAK_TOK)       /* | break */ \
    TOK(CASE_TOK)        /* | case */ \
    TOK(CHAN_TOK)        /* | chan */ \
    TOK(CONST_TOK)       /* | const */ \
    TOK(CONTINUE_TOK)    /* | continue */ \
    \
    TOK(DEFAULT_TOK)     /* | default */ \
    TOK(DEFER_TOK)       /* | defer */ \
    TOK(ELSE_TOK)        /* | else */ \
    TOK(FALLTHROUGH_TOK) /* | fallthrough */ \
    TOK(FOR_TOK)         /* | for */ \
    \
    TOK(FUNC_TOK)        /* | func */ \
    TOK(GO_TOK)          /* | go */ \
    TOK(GOTO_TOK)        /* | goto */ \
    TOK(IF_TOK)          /* | if */ \
    TOK(IMPORT_TOK)      /* | import */ \
    \
    TOK(INTERFACE_TOK)   /* | interface */ \
    TOK(MAP_TOK)         /* | map */ \
    TOK(PACKAGE_TOK)     /* | package */ \
    TOK(RANGE_TOK)       /* | range */ \
    TOK(RETURN_TOK)      /* | return */ \
    \
    TOK(SELECT_TOK)      /* | select */ \
    TOK(STRUCT_TOK)      /* | struct */ \
    TOK(SWITCH_TOK)      /* | switch */ \
    TOK(TYPE_TOK)        /* | type */ \
    TOKEND(VAR_TOK)          /* | var */ \

#define GENERATE_ENUM(ENUM) ENUM,
#define GENERATE_ENUM_END(ENUM) ENUM
#define GENERATE_STRING(STRING) #STRING,
#define GENERATE_STRING_END(STRING) #STRING

enum token_id {
    FOREACH_TOK(GENERATE_ENUM,GENERATE_ENUM_END)
};

extern char *token_id_string[];

typedef struct {
    char *key;
    enum token_id value;
} keyword;

typedef struct {
    enum token_id id;
    vector vec;
} token;

typedef struct {
    char current_char;
    FILE *input_stream;
    token tok;
    bool initialized;
} context;

struct state {
    struct state (*func)(context *ctx);
};


/* States */
struct state s_start(context *ctx);
struct state s_identificator(context *ctx);
struct state s_keyword(context *ctx);
struct state s_number_zero_start(context *ctx);
struct state s_hexnumber_start(context *ctx);
struct state s_hexnumber(context *ctx);
struct state s_number(context *ctx);
struct state s_number_dot(context *ctx);
struct state s_float(context *ctx);
struct state s_comment_start(context *ctx);
struct state s_comment_oneline(context *ctx);
struct state s_comment_multiline(context *ctx);
struct state s_comment_multiline_end(context *ctx);
struct state s_operator(context *ctx);
struct state s_operator_ellipsis(context* ctx);
struct state s_string(context *ctx);
struct state s_special_string(context *ctx);
struct state s_hexstring_start(context *ctx);
struct state s_hexstring_end(context *ctx);
struct state s_char_start(context *ctx);
struct state s_special_char(context *ctx);
struct state s_hexchar_start(context *ctx);
struct state s_hexchar_end(context *ctx);
struct state s_char_end(context *ctx);
struct state s_eot(context *ctx);
struct state s_error(context *ctx);

/* scanning */
token scanner_get_token(context *ctx, bool skip_whitespace_tokens);
void scanner_init(context *ctx, FILE *input_stream);

#endif /* GO_SCANER_H */