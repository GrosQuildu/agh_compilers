#include "go_scanner.h"

#define KEYWORD_LIST_SIZE (25)
keyword keyword_list[KEYWORD_LIST_SIZE] = {
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
};


#define OPERATOR_LIST_SIZE (47)
keyword operator_list[OPERATOR_LIST_SIZE] = {
    {"+", ADD_TOK}, 
    {"++", INC_TOK}, 
    {"+=", ADD_ASSIGN_TOK}, 
    {"-", SUB_TOK}, 
    {"--", DEC_TOK}, 
    {"-=", SUB_ASSIGN_TOK}, 
    {"*", MUL_TOK}, 
    {"*=", MUL_ASSIGN_TOK}, 
    {"/", QUO_TOK}, 
    {"/=", QUO_ASSIGN_TOK}, 
    {"%", REM_TOK}, 
    {"%=", REM_ASSIGN_TOK}, 
    {"&", AND_TOK}, 
    {"&^", AND_NOT_TOK}, 
    {"&^=", AND_NOT_ASSIGN_TOK}, 
    {"&&", LAND_TOK}, 
    {"&=", AND_ASSIGN_TOK}, 
    {"|", OR_TOK}, 
    {"|=", OR_ASSIGN_TOK}, 
    {"||", LOR_TOK}, 
    {"^", XOR_TOK}, 
    {"^=", XOR_ASSIGN_TOK}, 
    {"<", LSS_TOK}, 
    {"<-", ARROW_TOK}, 
    {"<<", SHL_TOK}, 
    {"<=", LEQ_TOK}, 
    {"<<=", SHL_ASSIGN_TOK}, 
    {">", GTR_TOK}, 
    {">=", GEQ_TOK}, 
    {">>", SHR_TOK}, 
    {">>=", SHR_ASSIGN_TOK}, 
    {"=", ASSIGN_TOK}, 
    {"==", EQL_TOK}, 
    {".", PERIOD_TOK}, 
    {"...", ELLIPSIS_TOK}, 
    {"(", LPAREN_TOK}, 
    {"[", LBRACK_TOK}, 
    {"{", LBRACE_TOK}, 
    {",", COMMA_TOK}, 
    {")", RPAREN_TOK}, 
    {"]", RBRACK_TOK}, 
    {"}", RBRACE_TOK}, 
    {"; ", SEMICOLON_TOK}, 
    {":", COLON_TOK}, 
    {":=", DEFINE_TOK}, 
    {"!", NOT_TOK}, 
    {"!=", NEQ_TOK}
};

char *token_id_string[] = {
    FOREACH_TOK(GENERATE_STRING,GENERATE_STRING_END)
};

/* States */
struct state s_start(context* ctx) {
    struct state next_state;
    bool is_operator = false;
    int i;
    vector_append(&ctx->tok.vec, ctx->current_char);

    if(is_letter(ctx->current_char))
        next_state.func = s_identificator;
    else if(ctx->current_char == '0')
        next_state.func = s_number_zero_start;
    else if(is_digit(ctx->current_char))
        next_state.func = s_number;
    else if(ctx->current_char == '\'')
        next_state.func = s_char_start;
    else if(ctx->current_char == '"')
        next_state.func = s_string;
    else if(ctx->current_char == '/')
        next_state.func = s_comment_start;
    else {
        for(i = 0; i < OPERATOR_LIST_SIZE; i++) {
            if(vector_cmp(&ctx->tok.vec, operator_list[i].key, strlen(operator_list[i].key))) {
                ctx->tok.id = operator_list[i].value;
                is_operator = true;
            }
        }
        if(is_operator)
            next_state.func = s_operator;
        else {
            ctx->tok.id = ERROR_TOK;
            next_state.func = s_eot;
            ctx->current_char = fgetc(ctx->input_stream); /* go to next byte */
        } 
    }
    
    return next_state;
}

/* identyficators and keywords */
struct state s_identificator(context* ctx) {
    struct state next_state;
    
    if(is_letter(ctx->current_char) || is_digit(ctx->current_char)) {
        vector_append(&ctx->tok.vec, ctx->current_char);
        next_state.func = s_identificator;
    } else {
        next_state = s_keyword(ctx);
    }

    return next_state;
}

struct state s_keyword(context* ctx) {
    struct state next_state = {s_eot};
    int i;
    ctx->tok.id = IDENT_TOK;

    for(i = 0; i < KEYWORD_LIST_SIZE; i++) {
        if(vector_cmp(&ctx->tok.vec, keyword_list[i].key, strlen(keyword_list[i].key)))
            ctx->tok.id = keyword_list[i].value;
    }

    return next_state;
}


/* numbers */
struct state s_number_zero_start(context* ctx) {
    struct state next_state;
    
    if(ctx->current_char == 'x') {
        vector_append(&ctx->tok.vec, ctx->current_char);
        next_state.func = s_hexnumber_start;
    } else if(is_digit(ctx->current_char)) {
        vector_append(&ctx->tok.vec, ctx->current_char);
        next_state.func = s_number;
    } else {
        ctx->tok.id = INT_TOK;
        next_state.func = s_eot;
    }

    return next_state;
}

struct state s_hexnumber_start(context* ctx) {
    struct state next_state;
    
    if(is_hexdigit(ctx->current_char)) {
        vector_append(&ctx->tok.vec, ctx->current_char);
        next_state.func = s_hexnumber;
    } else {
        ctx->tok.id = ERROR_TOK;
        next_state.func = s_eot;
    }

    return next_state;
}

struct state s_hexnumber(context* ctx) {
    struct state next_state;
    
    if(is_hexdigit(ctx->current_char)) {
        vector_append(&ctx->tok.vec, ctx->current_char);
        next_state.func = s_hexnumber;
    } else {
        ctx->tok.id = INT_TOK;
        next_state.func = s_eot;
    }

    return next_state;
}

struct state s_number(context* ctx) {
    struct state next_state;

    if(is_digit(ctx->current_char)) {
        vector_append(&ctx->tok.vec, ctx->current_char);
        next_state.func = s_number;
    } else if(ctx->current_char == 'i') {
        vector_append(&ctx->tok.vec, ctx->current_char);
        ctx->tok.id = IMAG_TOK;
        next_state.func = s_eot;
        ctx->current_char = fgetc(ctx->input_stream); /* go to next byte */
    } else if(ctx->current_char == '.') {
        vector_append(&ctx->tok.vec, ctx->current_char);
        next_state.func = s_number_dot;
    } else {
        ctx->tok.id = INT_TOK;
        next_state.func = s_eot;
    }

    return next_state;
}

struct state s_number_dot(context* ctx) {
    struct state next_state;
    
    if(is_digit(ctx->current_char)) {
        vector_append(&ctx->tok.vec, ctx->current_char);
        next_state.func = s_float;
    } else if(ctx->current_char == 'i') {
        vector_append(&ctx->tok.vec, ctx->current_char);
        ctx->tok.id = IMAG_TOK;
        next_state.func = s_eot;
        ctx->current_char = fgetc(ctx->input_stream); /* go to next byte */
    } else {
        ctx->tok.id = INT_TOK;
        next_state.func = s_eot;
    }
    return next_state;
}

struct state s_float(context* ctx) {
    struct state next_state;
    
    if(is_digit(ctx->current_char)) {
        vector_append(&ctx->tok.vec, ctx->current_char);
        next_state.func = s_float;
    } else if(ctx->current_char == 'i') {
        vector_append(&ctx->tok.vec, ctx->current_char);
        ctx->tok.id = IMAG_TOK;
        next_state.func = s_eot;
        ctx->current_char = fgetc(ctx->input_stream); /* go to next byte */
    } else {
        ctx->tok.id = FLOAT_TOK;
        next_state.func = s_eot;
    }
    return next_state;
}

/* comments */
struct state s_comment_start(context* ctx) {
    struct state next_state;
    
    if(ctx->current_char == '/') {
        vector_append(&ctx->tok.vec, ctx->current_char);
        next_state.func = s_comment_oneline;
    } else if(ctx->current_char == '*') {
        vector_append(&ctx->tok.vec, ctx->current_char);
        next_state.func = s_comment_multiline;
    } else {
        ctx->tok.id = ERROR_TOK;
        next_state.func = s_eot;
    }
    return next_state;
}

struct state s_comment_oneline(context* ctx) {
    struct state next_state;
    
    if(ctx->current_char != '\n') {
        vector_append(&ctx->tok.vec, ctx->current_char);
        next_state.func = s_comment_oneline;
    } else {
        ctx->tok.id = COMMENT_TOK;
        next_state.func = s_eot;
    }
    return next_state;
}

struct state s_comment_multiline(context* ctx) {
    struct state next_state;
    
    if(ctx->current_char == '*') {
        vector_append(&ctx->tok.vec, ctx->current_char);
        next_state.func = s_comment_multiline_end;
    } else if(ctx->current_char == EOF) {
        ctx->tok.id = ERROR_TOK;
        next_state.func = s_eot;
    } else {
        vector_append(&ctx->tok.vec, ctx->current_char);
        next_state.func = s_comment_multiline;
    }

    return next_state;
}

struct state s_comment_multiline_end(context* ctx) {
    struct state next_state;
    
    if(ctx->current_char == '/') {
        vector_append(&ctx->tok.vec, ctx->current_char);
        ctx->tok.id = COMMENT_TOK;
        next_state.func = s_eot;
        ctx->current_char = fgetc(ctx->input_stream); /* go to next byte */
    } else if(ctx->current_char == '*') {
        vector_append(&ctx->tok.vec, ctx->current_char);
        next_state.func = s_comment_multiline_end;
    } else if(ctx->current_char == EOF) {
        ctx->tok.id = ERROR_TOK;
        next_state.func = s_eot;
    } else {
        vector_append(&ctx->tok.vec, ctx->current_char);
        next_state.func = s_comment_multiline;
    }

    return next_state;
}

/* operators */
struct state s_operator(context* ctx) {
    struct state next_state;
    int i;
    bool new_char_extends_operator = false;
    vector_append(&ctx->tok.vec, ctx->current_char);

    if(ctx->current_char == '.') {
        /* second dot in ellipsis token*/
        next_state.func = s_operator_ellipsis;
        return next_state;
    }

    for(i = 0; i < OPERATOR_LIST_SIZE; i++) {
        if(vector_cmp(&ctx->tok.vec, operator_list[i].key, strlen(operator_list[i].key))) {
            ctx->tok.id = operator_list[i].value;
            new_char_extends_operator = true;
        }
    }

    if(new_char_extends_operator)
        next_state.func = s_operator;
    else {
        ctx->tok.vec.current--;
        next_state.func = s_eot;
    }

    return next_state;
}

struct state s_operator_ellipsis(context* ctx) {
    struct state next_state = {s_eot};

    if(ctx->current_char == '.') {
        /* third dot in ellipsis token*/
        vector_append(&ctx->tok.vec, ctx->current_char);
        ctx->tok.id = ELLIPSIS_TOK;
    } else
        ctx->tok.id = ERROR_TOK;

    return next_state;
}

/* strings */
struct state s_string(context* ctx) {
    struct state next_state;
    
    if(ctx->current_char == '\\') {
        vector_append(&ctx->tok.vec, ctx->current_char);
        next_state.func = s_special_string;
    } else if(ctx->current_char == '"') {
        vector_append(&ctx->tok.vec, ctx->current_char);
        ctx->tok.id = STRING_TOK;
        next_state.func = s_eot;
        ctx->current_char = fgetc(ctx->input_stream); /* go to next byte */
    } else if(ctx->current_char == EOF) {
        ctx->tok.id = ERROR_TOK;
        next_state.func = s_eot;
    } else {
        vector_append(&ctx->tok.vec, ctx->current_char);
        next_state.func = s_string;
    }

    return next_state;
}

struct state s_special_string(context* ctx) {
    struct state next_state;
    
    if(ctx->current_char == 'x') {
        vector_append(&ctx->tok.vec, ctx->current_char);
        next_state.func = s_hexstring_start;
    } else if(is_specialchar(ctx->current_char)) {
        vector_append(&ctx->tok.vec, ctx->current_char);
        next_state.func = s_string;
    } else {
        ctx->tok.id = ERROR_TOK;
        next_state.func = s_eot;
    }

    return next_state;
}

struct state s_hexstring_start(context* ctx) {
    struct state next_state;
    
    if(is_hexdigit(ctx->current_char)) {
        vector_append(&ctx->tok.vec, ctx->current_char);
        next_state.func = s_hexstring_end;
    } else {
        ctx->tok.id = ERROR_TOK;
        next_state.func = s_eot;
    }

    return next_state;
}

struct state s_hexstring_end(context* ctx) {
    struct state next_state;
    
    if(is_hexdigit(ctx->current_char)) {
        vector_append(&ctx->tok.vec, ctx->current_char);
        next_state.func = s_string;
    } else {
        ctx->tok.id = ERROR_TOK;
        next_state.func = s_eot;
    }

    return next_state;
}

/* char */
struct state s_char_start(context* ctx) {
    struct state next_state;
    
    if(ctx->current_char == '\\') {
        vector_append(&ctx->tok.vec, ctx->current_char);
        next_state.func = s_special_char;
    } else if(ctx->current_char == '\'') {
        ctx->tok.id = ERROR_TOK;
        next_state.func = s_eot;
        ctx->current_char = fgetc(ctx->input_stream); /* go to next byte */
    } else if(ctx->current_char == EOF) {
        ctx->tok.id = ERROR_TOK;
        next_state.func = s_eot;
    } else
        next_state.func = s_char_end;

    return next_state;
}

struct state s_special_char(context* ctx) {
    struct state next_state;
    
    if(ctx->current_char == 'x') {
        vector_append(&ctx->tok.vec, ctx->current_char);
        next_state.func = s_hexchar_start;
    } else if(is_specialchar(ctx->current_char)) {
        vector_append(&ctx->tok.vec, ctx->current_char);
        next_state.func = s_char_end;
    } else {
        ctx->tok.id = ERROR_TOK;
        next_state.func = s_eot;
    }

    return next_state;
}

struct state s_hexchar_start(context* ctx) {
    struct state next_state;
    
    if(is_hexdigit(ctx->current_char)) {
        vector_append(&ctx->tok.vec, ctx->current_char);
        next_state.func = s_hexchar_end;
    } else {
        ctx->tok.id = ERROR_TOK;
        next_state.func = s_eot;
    }

    return next_state;
}

struct state s_hexchar_end(context* ctx) {
    struct state next_state;
    
    if(is_hexdigit(ctx->current_char)) {
        vector_append(&ctx->tok.vec, ctx->current_char);
        next_state.func = s_char_end;
    } else {
        ctx->tok.id = ERROR_TOK;
        next_state.func = s_eot;
    }

    return next_state;
}

struct state s_char_end(context* ctx) {
    struct state next_state;
    
    if(ctx->current_char == '\'') {
        vector_append(&ctx->tok.vec, ctx->current_char);
        ctx->tok.id = CHAR_TOK;
        next_state.func = s_eot;
        ctx->current_char = fgetc(ctx->input_stream); /* go to next byte */
    } else {
        ctx->tok.id = ERROR_TOK;
        next_state.func = s_eot;
    }

    return next_state;
}

/* special */
struct state s_eot(context* ctx) {
    struct state ret = {s_eot};
    return ret;
}

struct state s_error(context* ctx) {
    struct state ret = {s_error};
    return ret;
}

void scanner_init(context *ctx, FILE *input_stream) {
    ctx->input_stream = input_stream;
    ctx->current_char = fgetc(ctx->input_stream);
    ctx->initialized = true;
} 

token scanner_get_token(context *ctx, bool skip_whitespace_tokens) {
    struct state current_state;
    bool whitespace_found = false;

    vector_init(&ctx->tok.vec, 32);
    
    if(skip_whitespace_tokens) {
        while(ctx->current_char != EOF && is_whitespace(ctx->current_char))
            ctx->current_char = fgetc(ctx->input_stream);
    } else {
        if(is_whitespace(ctx->current_char))
            whitespace_found = true;
        while(ctx->current_char != EOF && is_whitespace(ctx->current_char)) {
            vector_append(&ctx->tok.vec, ctx->current_char);
            ctx->current_char = fgetc(ctx->input_stream);
        }
    }

    if(ctx->current_char == EOF) {
        ctx->tok.id = EOF_TOK;
        vector_append(&ctx->tok.vec, 'E');
        vector_append(&ctx->tok.vec, '0');
        vector_append(&ctx->tok.vec, 'F');
        return ctx->tok;
    }
    
    if(whitespace_found) {
        ctx->tok.id = WHITESPACE_TOK;
        return ctx->tok;
    }

    current_state = s_start(ctx);
    while(current_state.func != s_eot) {
        ctx->current_char = fgetc(ctx->input_stream);
        current_state = (*current_state.func)(ctx);
    }

    return ctx->tok;
}
