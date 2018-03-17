#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "go_scaner.h"

/* States */
struct state s_start(context* ctx) {
    struct state next_state;
    vector_init(&ctx->tok.vec, 32);
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
    else
        next_state.func = s_operator;

    return next_state;
}

/* identyficators and keywords */
struct state s_identificator(context* ctx) {
    struct state next_state;
    ctx->current_char = fgetc(ctx->input_stream);
    
    if(is_letter(ctx->current_char) || is_digit(ctx->current_char)) {
        vector_append(&ctx->tok.vec, ctx->current_char);
        next_state.func = s_identificator;
    } else
        next_state.func = s_keyword;

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
    ctx->current_char = fgetc(ctx->input_stream);
    
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
    ctx->current_char = fgetc(ctx->input_stream);
    
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
    ctx->current_char = fgetc(ctx->input_stream);
    
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
    ctx->current_char = fgetc(ctx->input_stream);

    if(is_digit(ctx->current_char)) {
        vector_append(&ctx->tok.vec, ctx->current_char);
        next_state.func = s_number;
    } else if(ctx->current_char == 'i') {
        vector_append(&ctx->tok.vec, ctx->current_char);
        ctx->tok.id = IMAG_TOK;
        next_state.func = s_eot;
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
    ctx->current_char = fgetc(ctx->input_stream);
    
    if(is_digit(ctx->current_char)) {
        vector_append(&ctx->tok.vec, ctx->current_char);
        next_state.func = s_float;
    } else if(ctx->current_char == 'i') {
        vector_append(&ctx->tok.vec, ctx->current_char);
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
        vector_append(&ctx->tok.vec, ctx->current_char);
        next_state.func = s_float;
    } else if(ctx->current_char == 'i') {
        vector_append(&ctx->tok.vec, ctx->current_char);
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
    ctx->current_char = fgetc(ctx->input_stream);
    
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
    ctx->current_char = fgetc(ctx->input_stream);
    
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
    ctx->current_char = fgetc(ctx->input_stream);
    
    if(ctx->current_char == '/') {
        vector_append(&ctx->tok.vec, ctx->current_char);
        ctx->tok.id = COMMENT_TOK;
        next_state.func = s_eot;
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
    struct state next_state = {s_eot};
    char operators[] = {'+', '-', '*'};

    if(in_array(ctx->current_char, operators, 3)) {
        vector_append(&ctx->tok.vec, ctx->current_char);
        ctx->tok.id = SUB_TOK;
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
        vector_append(&ctx->tok.vec, ctx->current_char);
        next_state.func = s_special_string;
    } else if(ctx->current_char == '"') {
        vector_append(&ctx->tok.vec, ctx->current_char);
        ctx->tok.id = STRING_TOK;
        next_state.func = s_eot;
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
    ctx->current_char = fgetc(ctx->input_stream);
    
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
    ctx->current_char = fgetc(ctx->input_stream);
    
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
    ctx->current_char = fgetc(ctx->input_stream);
    
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
    ctx->current_char = fgetc(ctx->input_stream);
    
    if(ctx->current_char == '\\') {
        vector_append(&ctx->tok.vec, ctx->current_char);
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
    ctx->current_char = fgetc(ctx->input_stream);
    
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
    ctx->current_char = fgetc(ctx->input_stream);
    
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
    ctx->current_char = fgetc(ctx->input_stream);
    
    if(ctx->current_char == '\'') {
        vector_append(&ctx->tok.vec, ctx->current_char);
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
    struct state current_state = {s_start};

    context ctx;
    ctx.input_stream = input_stream;
    ctx.current_char = fgetc(ctx.input_stream);

    while(ctx.current_char != EOF && is_whitespace(ctx.current_char))
        ctx.current_char = fgetc(ctx.input_stream);

    if(ctx.current_char == EOF) {
        ctx.tok.id = EOF_TOK;
        vector_init(&ctx.tok.vec, 3);
        vector_append(&ctx.tok.vec, 'E');
        vector_append(&ctx.tok.vec, '0');
        vector_append(&ctx.tok.vec, 'F');
        return ctx.tok;
    }

    while(current_state.func != s_eot)
        current_state = (*current_state.func)(&ctx);

    return ctx.tok;
}

int main(int argc, char *argv[]) {
    FILE *input_stream;
    char *input_filename;
    bool debug = false;

    bool end_of_tokens = false;
    token current_token;

    if(argc == 3 || argc == 2) {
        if(argc == 3 && (strcmp(argv[2], "-d") == 0 || strcmp(argv[2],"--debug") == 0))
            debug = true;
        input_filename = argv[1];
    } else {
        if(argc == 1)
            printf("Usage: %s filename.go [-d | --debug]\n", argv[0]);
        else
            printf("Usage: ./go_scaner filename.go [-d | --debug]\n");
        exit(EXIT_FAILURE);
    }
    
    input_stream = fopen(input_filename, "r");
    if(input_stream == NULL)
        exit_error("Failure opening input file");

    if(debug) {
        puts("Tokens:");
        while(end_of_tokens == false) {
            current_token = scaner_get_token(input_stream);
            printf("- %s: ", token_id_string[current_token.id]);
            vector_print(&current_token.vec);
            puts("\n--------");
            if(current_token.id == EOF_TOK)
                end_of_tokens = true;

            vector_delete(&current_token.vec);
        }
    }

    return 0;
}
