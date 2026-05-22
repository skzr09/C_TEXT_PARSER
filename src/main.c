#include <stdio.h>
//#include "parser.h"

int main(int argc, char *argv[]) {

    // error: no input <filename>
    if (argc < 2) {
        fprintf(stderr, "[Error] Usage: %s <filename>\n", argv[0]);
        return 1; // TODO: Update to EXIT_FAILURE
    }

    const char *filename = argv[1];
    printf("Processing file: %s\n", filename);


    printf("HELLO\n");

    if (argc > 1) {
        printf("Argument[1]: %s\n", argv[1]);
    } else {
        printf("No arguments\n");
    }
    return 0;
}
