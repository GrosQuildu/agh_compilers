/* Helpers */
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
    char whitespaces[] = {' ', '\n', '\t', '\r'};
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
    char specialchars[] = {'a', 'b', 'f', 'n', 'r', 't', 'v', '\\', '\'', '"'};
    return in_array(c, specialchars, 10);
}

typedef struct {
    char *beginning;
    char *current;
    uint32_t size;
} vector;

void vector_init(vector *vec, uint32_t size) {
    vec->beginning = malloc(size);
    if(vec->beginning == NULL)
        exit_error("Error in malloc in vector_init: ");
    vec->current = vec->beginning;
    vec->size = size;
}

void vector_append(vector *vec, char c) {
    if(vec->current >= vec->beginning + vec->size) {
        vec->beginning = realloc(vec->beginning, vec->size*2);
        if(vec->beginning == NULL)
            exit_error("Error in append:");
    }
    *(vec->current)++ = c;
}

bool vector_cmp(vector *vec, char *buf) {
    return memcmp(vec->beginning, buf, vec->current-vec->beginning);
}