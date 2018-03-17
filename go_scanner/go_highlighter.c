#include "go_highlighter.h"

void highlighter_init(FILE *output_stream) {
    char *html_prefix = "<!DOCTYPE html>\n"
                        "<html>\n"
                        "<head>\n"
                        "    <title>Go highlight</title>\n"
                        "</head>\n"
                        "<body>\n";
    fwrite(html_prefix, 1, strlen(html_prefix), output_stream);
}

void highlighter_translate(token current_token, FILE *output_stream) {
    fprintf(output_stream, "%s\n", token_id_string[current_token.id]);
}

void highlighter_end(FILE *output_stream) {
    char *html_suffix = "</body>\n"
                        "</html>";
    fwrite(html_suffix, 1, strlen(html_suffix), output_stream);
}
