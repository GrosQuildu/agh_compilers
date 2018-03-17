#ifndef HELPERS_H
#define HELPERS_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>


void exit_error(char *msg);

bool in_array(char c, char array[], size_t array_size);

bool is_whitespace(char c);
bool is_letter(char c);
bool is_digit(char c);
bool is_hexdigit(char c);
bool is_specialchar(char c);
bool is_printable(char c);
bool is_operator(char c);

typedef struct {
    char *beginning;
    char *current;
    uint32_t max_size;
} vector;

void vector_init(vector *vec, uint32_t size);
void vector_delete(vector *vec);
void vector_append(vector *vec, char c);
bool vector_cmp(vector *vec, char *buf, uint32_t buf_size);
void vector_print(vector *vec);
void vector_print_html(vector *vec, FILE *output_stream);

#endif /* HELPERS_H */