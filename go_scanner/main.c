#define _POSIX_C_SOURCE 1  /* for flock */
#include "go_highlighter.h"

int main(int argc, char *argv[]) {
    char *input_filename, *output_filename;
    FILE *input_stream, *output_stream;
    bool debug = false;

    bool end_of_tokens = false;
    context ctx;
    token current_token;

    /* Argument parsing */
    if(argc == 3) {
        input_filename = argv[1];
        if(strcmp(argv[2], "-d") == 0 || strcmp(argv[2],"--debug") == 0)
            debug = true;
        else
            output_filename = argv[2];
    } else {
        if(argc >= 1)
            printf("Usage: %s input.go [output.html | -d | --debug]\n", argv[0]);
        else
            printf("Usage: ./go_scanner input.go [output.html | -d | --debug]\n");
        exit(EXIT_FAILURE);
    }
    
    /* Open and lock in/out files */
    input_stream = fopen(input_filename, "r");
    if(input_stream == NULL)
        exit_error("Failure opening input file");
    if(flock(fileno(input_stream), LOCK_SH | LOCK_NB) < 0)
        exit_error("Failure locking input file");

    if(!debug) {
        output_stream = fopen(output_filename, "w");
        if(output_stream == NULL)
            exit_error("Failure opening output file");
        if(flock(fileno(output_stream), LOCK_EX | LOCK_NB) < 0)
            exit_error("Failure locking output file");
    }

    /* Initialize context */
    scanner_init(&ctx, input_stream);

    if(debug) {
    /* Debug - only list tokens */
        while(end_of_tokens == false) {
            current_token = scanner_get_token(&ctx, true);
            puts("Tokens:");
            printf("- %s: ", token_id_string[current_token.id]);
            vector_print(&current_token.vec);
            puts("\n--------");

            if(current_token.id == EOF_TOK)
                end_of_tokens = true;
            vector_delete(&current_token.vec);
        }

    } else {
    /* Go2HTML - write to output file*/
        highlighter_init(output_stream);

        while(end_of_tokens == false) {
            current_token = scanner_get_token(&ctx, false);

            if(current_token.id == EOF_TOK)
                end_of_tokens = true;
            else
                highlighter_translate(current_token, output_stream);
            vector_delete(&current_token.vec);
        }

        highlighter_end(output_stream);
        if(flock(fileno(output_stream), LOCK_UN) < 0)
            exit_error("Failure unlocking output file");
        fclose(output_stream);
    }

    if(flock(fileno(input_stream), LOCK_UN) < 0)
        exit_error("Failure unlocking input file");
    fclose(input_stream);
    return 0;
}
