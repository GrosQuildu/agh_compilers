#include <stdlib.h>
#include <stdio.h>

#include "go_scaner.h"

/* States */
struct StateFunc state_identificator() {
    struct StateFunc ret;
    ret.func = state_keyword;
    return ret;
}

struct StateFunc state_keyword() {
    struct StateFunc ret;
    ret.func = state_keyword;
    return ret;
}

struct StateFunc state_number() {
    struct StateFunc ret;
    ret.func = state_keyword;
    return ret;
}

struct StateFunc state_operator() {
    struct StateFunc ret;
    ret.func = state_keyword;
    return ret;
}

struct StateFunc state_string() {
    struct StateFunc ret;
    ret.func = state_keyword;
    return ret;
}



int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Wrong no. of args, should be 2, is %d\n", argc);
        exit(EXIT_FAILURE);
    }
    
    

    return 0;
}
