#ifndef GO_HIGHLIGHTER_H
#define GO_HIGHLIGHTER_H

#include "go_scanner.h"

void highlighter_init(FILE *output_stream);
void highlighter_translate(token current_token, FILE *output_stream);
void highlighter_end(FILE *output_stream);

#endif /* GO_HIGHLIGHTER_H */