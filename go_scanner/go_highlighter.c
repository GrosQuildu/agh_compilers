#include "go_highlighter.h"

void highlighter_init(FILE *output_stream) {
    char *html_prefix = "<!DOCTYPE html>\n"
                        "<html>\n"
                        "<head>\n"
                        "    <meta charset=\"utf-8\">"
                        "    <title>Go highlight</title>\n";
    char *html_prefix2 = "</head>\n"
                         "<body>\n";
    FILE *colors_css;
    char c;

    fwrite(html_prefix, 1, strlen(html_prefix), output_stream);

    colors_css = fopen("colors.css", "r");
    if(colors_css == NULL) {
        perror("Error opening colors.css");
        exit(EXIT_FAILURE);
    }

    while((c = fgetc(colors_css)) != EOF)
          fputc(c, output_stream);
    fclose(colors_css);
    
    fwrite(html_prefix2, 1, strlen(html_prefix2), output_stream);
}

void highlighter_translate(token current_token, FILE *output_stream) {
    if(current_token.id != WHITESPACE_TOK)
        fprintf(output_stream, "<div class=\"%s\">", token_id_string[current_token.id]);
    vector_print_html(&current_token.vec, output_stream);
    if(current_token.id != WHITESPACE_TOK)
        fprintf(output_stream, "</div>");
}

void highlighter_end(FILE *output_stream) {
    char *html_suffix = "</body>\n"
                        "</html>";
    fwrite(html_suffix, 1, strlen(html_suffix), output_stream);
}
