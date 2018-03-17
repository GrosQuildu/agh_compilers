#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "go_scaner.h"

/* States */
struct state s_start(context* ctx) {
    struct state next_state;
    vector_init(ctx->tok.vec, 32);
    vector_append(ctx->tok.vec, ctx->current_char);

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
    else
        next_state.func = s_operator; //todo not all chars all operators

    return next_state;
}

/* identyficators and keywords */
struct state s_identificator(context* ctx) {
    struct state next_state;
    ctx->current_char = fgetc(ctx->input_stream);
    
    if(is_letter(ctx->current_char) || is_digit(ctx->current_char)) {
        vector_append(ctx->tok.vec, ctx->current_char);
        next_state.func = s_identificator;
    } else
        next_state.func = s_keyword;

    return next_state;
}

struct state s_keyword(context* ctx) {
    struct state next_state = {s_eot};
    ctx->tok.id = IDENT_TOK;

    for(int i = 0; i < keyword_list_size; i++) {
        if(vector_cmp(ctx->tok.vec, keyword_list[i].key))
            ctx->tok.id = keyword_list[i].value;
    }

    return next_state;
}


/* numbers */
struct state s_number_zero_start(context* ctx) {
    struct state next_state;
    ctx->current_char = fgetc(ctx->input_stream);
    
    if(ctx->current_char == 'x') {
        vector_append(ctx->tok.vec, ctx->current_char);
        next_state.func = s_hexnumber_start;
    } else if(is_digit(ctx->current_char)) {
        vector_append(ctx->tok.vec, ctx->current_char);
        next_state.func = s_number;
    } else {
        ctx->tok.id = INT_TOK;
        next_state.func = s_eot;
    }

    return next_state;
}

struct state s_hexnumber_start(context* ctx) {
    struct state next_state;
    ctx->current_char = fgetc(ctx->input_stream);
    
    if(is_hexdigit(ctx->current_char)) {
        vector_append(ctx->tok.vec, ctx->current_char);
        next_state.func = s_hexnumber;
    } else {
        ctx->tok.id = ERROR_TOK;
        next_state.func = s_eot;
    }

    return next_state;
}

struct state s_hexnumber(context* ctx) {
    struct state next_state;
    ctx->current_char = fgetc(ctx->input_stream);
    
    if(is_hexdigit(ctx->current_char)) {
        vector_append(ctx->tok.vec, ctx->current_char);
        next_state.func = s_hexnumber;
    } else {
        ctx->tok.id = INT_TOK;
        next_state.func = s_eot;
    }

    return next_state;
}

struct state s_number(context* ctx) {
    struct state next_state;
    ctx->current_char = fgetc(ctx->input_stream);

    if(is_digit(ctx->current_char)) {
        vector_append(ctx->tok.vec, ctx->current_char);
        next_state.func = s_number;
    } else if(ctx->current_char == 'i') {
        vector_append(ctx->tok.vec, ctx->current_char);
        ctx->tok.id = IMAG_TOK;
        next_state.func = s_eot;
    } else if(ctx->current_char == '.') {
        vector_append(ctx->tok.vec, ctx->current_char);
        next_state.func = s_number_dot;
    } else {
        ctx->tok.id = INT_TOK;
        next_state.func = s_eot;
    }

    return next_state;
}

struct state s_number_dot(context* ctx) {
    struct state next_state;
    ctx->current_char = fgetc(ctx->input_stream);
    
    if(is_digit(ctx->current_char)) {
        vector_append(ctx->tok.vec, ctx->current_char);
        next_state.func = s_float;
    } else if(ctx->current_char == 'i') {
        vector_append(ctx->tok.vec, ctx->current_char);
        ctx->tok.id = IMAG_TOK;
        next_state.func = s_eot;
    } else {
        ctx->tok.id = INT_TOK;
        next_state.func = s_eot;
    }
    return next_state;
}

struct state s_float(context* ctx) {
    struct state next_state;
    ctx->current_char = fgetc(ctx->input_stream);
    
    if(is_digit(ctx->current_char)) {
        vector_append(ctx->tok.vec, ctx->current_char);
        next_state.func = s_float;
    } else if(ctx->current_char == 'i') {
        vector_append(ctx->tok.vec, ctx->current_char);
        ctx->tok.id = IMAG_TOK;
        next_state.func = s_eot;
    } else {
        ctx->tok.id = FLOAT_TOK;
        next_state.func = s_eot;
    }
    return next_state;
}

/* comments */
struct state s_comment_start(context* ctx) {
    struct state next_state;
    ctx->current_char = fgetc(ctx->input_stream);
    
    if(ctx->current_char == '/') {
        vector_append(ctx->tok.vec, ctx->current_char);
        next_state.func = s_comment_oneline;
    } else if(ctx->current_char == '*') {
        vector_append(ctx->tok.vec, ctx->current_char);
        next_state.func = s_comment_multiline;
    } else {
        ctx->tok.id = ERROR_TOK;
        next_state.func = s_eot;
    }
    return next_state;
}

struct state s_comment_oneline(context* ctx) {
    struct state next_state;
    ctx->current_char = fgetc(ctx->input_stream);
    
    if(ctx->current_char == '\n') {
        vector_append(ctx->tok.vec, ctx->current_char);
        next_state.func = s_comment_oneline;
    } else {
        ctx->tok.id = COMMENT_TOK;
        next_state.func = s_eot;
    }
    return next_state;
}

struct state s_comment_multiline(context* ctx) {
    struct state next_state;
    ctx->current_char = fgetc(ctx->input_stream);
    
    if(ctx->current_char == '*') {
        vector_append(ctx->tok.vec, ctx->current_char);
        next_state.func = s_comment_multiline_end;
    } else if(ctx->current_char == EOF) {
        ctx->tok.id = ERROR_TOK;
        next_state.func = s_eot;
    } else
        next_state.func = s_comment_multiline;

    return next_state;
}

struct state s_comment_multiline_end(context* ctx) {
    struct state next_state;
    ctx->current_char = fgetc(ctx->input_stream);
    
    if(ctx->current_char == '/') {
        vector_append(ctx->tok.vec, ctx->current_char);
        ctx->tok.id = COMMENT_TOK;
        next_state.func = s_eot;
    } else if(ctx->current_char == EOF) {
        ctx->tok.id = ERROR_TOK;
        next_state.func = s_eot;
    } else
        next_state.func = s_comment_multiline;

    return next_state;
}

/* operators */
struct state s_operator(context* ctx) {
    struct state next_state = {s_eot};

    if(in_array(ctx->current_char, {'+', '-', '*'})) {
        vector_append(ctx->tok.vec, ctx->current_char);
        ctx->tok.id = OPERATOR_TOK;
    } else {
        ctx->tok.id = ERROR_TOK;
    }
    return next_state;
}

/* strings */
struct state s_string(context* ctx) {
    struct state next_state;
    ctx->current_char = fgetc(ctx->input_stream);
    
    if(ctx->current_char == '\\') {
        vector_append(ctx->tok.vec, ctx->current_char);
        next_state.func = s_special_string;
    } else if(ctx->current_char == '"') {
        vector_append(ctx->tok.vec, ctx->current_char);
        ctx->tok.id = STRING_TOK;
        next_state.func = s_eot;
    } else if(ctx->current_char == EOF) {
        ctx->tok.id = ERROR_TOK;
        next_state.func = s_eot;
    } else
        next_state.func = s_string;

    return next_state;
}

struct state s_special_string(context* ctx) {
    struct state next_state;
    ctx->current_char = fgetc(ctx->input_stream);
    
    if(ctx->current_char == 'x') {
        vector_append(ctx->tok.vec, ctx->current_char);
        next_state.func = s_hexstring_start;
    } else if(is_specialchar(ctx->current_char)) {
        vector_append(ctx->tok.vec, ctx->current_char);
        next_state.func = s_string;
    } else {
        ctx->tok.id = ERROR_TOK;
        next_state.func = s_eot;
    }

    return next_state;
}

struct state s_hexstring_start(context* ctx) {
    struct state next_state;
    ctx->current_char = fgetc(ctx->input_stream);
    
    if(is_hexdigit(ctx->current_char)) {
        vector_append(ctx->tok.vec, ctx->current_char);
        next_state.func = s_hexstring_end;
    } else {
        ctx->tok.id = ERROR_TOK;
        next_state.func = s_eot;
    }

    return next_state;
}

struct state s_hexstring_end(context* ctx) {
    struct state next_state;
    ctx->current_char = fgetc(ctx->input_stream);
    
    if(is_hexdigit(ctx->current_char)) {
        vector_append(ctx->tok.vec, ctx->current_char);
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
    ctx->current_char = fgetc(ctx->input_stream);
    
    if(ctx->current_char == '\\') {
        vector_append(ctx->tok.vec, ctx->current_char);
        next_state.func = s_special_char;
    } else if(ctx->current_char == '\'') {
        ctx->tok.id = ERROR_TOK;
        next_state.func = s_eot;
    } else if(ctx->current_char == EOF) {
        ctx->tok.id = ERROR_TOK;
        next_state.func = s_eot;
    } else
        next_state.func = s_char_end;

    return next_state;
}

struct state s_special_char(context* ctx) {
    struct state next_state;
    ctx->current_char = fgetc(ctx->input_stream);
    
    if(ctx->current_char == 'x') {
        vector_append(ctx->tok.vec, ctx->current_char);
        next_state.func = s_hexchar_start;
    } else if(is_specialchar(ctx->current_char)) {
        vector_append(ctx->tok.vec, ctx->current_char);
        next_state.func = s_char_end;
    } else {
        ctx->tok.id = ERROR_TOK;
        next_state.func = s_eot;
    }

    return next_state;
}

struct state s_hexchar_start(context* ctx) {
    struct state next_state;
    ctx->current_char = fgetc(ctx->input_stream);
    
    if(is_hexdigit(ctx->current_char)) {
        vector_append(ctx->tok.vec, ctx->current_char);
        next_state.func = s_hexchar_end;
    } else {
        ctx->tok.id = ERROR_TOK;
        next_state.func = s_eot;
    }

    return next_state;
}

struct state s_hexchar_end(context* ctx) {
    struct state next_state;
    ctx->current_char = fgetc(ctx->input_stream);
    
    if(is_hexdigit(ctx->current_char)) {
        vector_append(ctx->tok.vec, ctx->current_char);
        next_state.func = s_char_end;
    } else {
        ctx->tok.id = ERROR_TOK;
        next_state.func = s_eot;
    }

    return next_state;
}

struct state s_char_end(context* ctx) {
    struct state next_state;
    ctx->current_char = fgetc(ctx->input_stream);
    
    if(ctx->current_char == '\'') {
        vector_append(ctx->tok.vec, ctx->current_char);
        ctx->tok.id = CHAR_TOK;
        next_state.func = s_eot;
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

token scaner_get_token(FILE *input_stream) {
    context ctx;
    ctx.input_stream = input_stream;
    ctx.current_char = fgetc(ctx.input_stream);

    while(ctx.current_char != EOF && is_whitespace(ctx.current_char))
        ctx.current_char = fgetc(ctx.input_stream);

    if(ctx.current_char == EOF) {
        ctx.tok = EOF_TOK;
        return ctx.tok;
    }

    struct state current_state = {s_start};
    while(current_state.func != s_eot)
        current_state = (*current_state.func)(&ctx);

    return ctx.tok;
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Wrong no. of args, should be 2, is %d\n", argc);
        exit(EXIT_FAILURE);
    }
    
    FILE *input_stream = fopen(argv[1], "r");
    if(f == NULL)
        exit_error("Failure opening input file:");

    scaner_get_token(input_stream)

    return 0;
}
