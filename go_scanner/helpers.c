#include "helpers.h"

void exit_error(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

bool in_array(char c, char array[], size_t array_size) {
    int i;
    for (i = 0; i < array_size; ++i) {
        if(array[i] == c)
            return true;
    }
    return false;
}

bool is_whitespace(char c) {
    char whitespaces[4] = {' ', '\n', '\t', '\r'};
    return in_array(c, whitespaces, 4);
}

bool is_letter(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_');
}

bool is_digit(char c) {
    return (c >= '0' && c <= '9');
}

bool is_hexdigit(char c) {
    return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f'));
}

bool is_specialchar(char c) {
    char specialchars[10] = {'a', 'b', 'f', 'n', 'r', 't', 'v', '\\', '\'', '"'};
    return in_array(c, specialchars, 10);
}

bool is_printable(char c) {
  char printable[33] = {'!', '"', '#', '$', '%', '&', '\'', '(', ')',
                       '*', '+', ',', '-', '.', '/', ':', ';', '<',
                       '=', '>', '?', '@', '[', '\\', ']', '^', '_',
                       '`', '{', '|', '}', '~'};
  return is_letter(c) || is_digit(c) || in_array(c, printable, 33);
}

bool is_operator(char c) {
  char operators[20] = {'+', '-', '*', '/', '%', '&', '|', '^',
                        '<', '>', '=', '(', ')', '[', ']', '.',
                        ';', ':', '!', ','};
  return in_array(c, operators, 20);
}

void vector_init(vector *vec, uint32_t size) {
    vec->beginning = malloc(size);
    if(vec->beginning == NULL)
        exit_error("Error in malloc in vector_init");
    vec->current = vec->beginning;
    vec->max_size = size;
}

void vector_delete(vector *vec) {
    free(vec->beginning);
    vec->beginning = NULL;
    vec->current = NULL;
    vec->max_size = 0;
}

void vector_append(vector *vec, char c) {
    size_t current_size;
    if(vec->current - vec->beginning >= vec->max_size) {
        current_size = vec->current - vec->beginning;
        vec->beginning = realloc(vec->beginning, vec->max_size*2);
        if(vec->beginning == NULL)
            exit_error("Error in append");
        vec->current = vec->beginning + current_size;
        vec->max_size = vec->max_size*2;
    }
    *(vec->current)++ = c;
}

bool vector_cmp(vector *vec, char *buf, uint32_t buf_size) {
    return (buf_size == vec->current - vec->beginning) && (strncmp(vec->beginning, buf, buf_size) == 0);
}

void vector_print(vector *vec) {
  char *vec_ptr;
  for (vec_ptr = vec->beginning; vec_ptr < vec->current; vec_ptr++) {
    if(is_printable(*vec_ptr))
      putchar(*vec_ptr);
    else
      printf("\\x%02x", *vec_ptr);
  }
}

void vector_print_html(vector *vec, FILE *output_stream) {
  char *vec_ptr;
  for (vec_ptr = vec->beginning; vec_ptr < vec->current; vec_ptr++) {
    if(*vec_ptr == '&')
      fwrite("&amp;", 5, 1, output_stream);
    else if(*vec_ptr == '<')
      fwrite("&lt;", 4, 1, output_stream);
    else if(*vec_ptr == '>')
      fwrite("&gt;", 4, 1, output_stream);
    else if(*vec_ptr == '\'')
      fwrite("&apos;", 6, 1, output_stream);
    else if(*vec_ptr == '"')
      fwrite("&quot;", 6, 1, output_stream);
    else if(*vec_ptr == '\n')
      fwrite("<br/>\n", 6, 1, output_stream);
    else if(*vec_ptr == ' ')
      fwrite("&nbsp;", 6, 1, output_stream);
    else
      fwrite(vec_ptr, 1, 1, output_stream);
  }
}