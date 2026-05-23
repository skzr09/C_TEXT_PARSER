#include <stdio.h>
#include "parser.h"
#include "logger.h"

int main(int argc, char *argv[]) {

    // error: no input <filename>
    if (argc < 2) {
        fprintf(stderr, "[Error] Usage: %s <filename>\n", argv[0]);
        return 1; // TODO: Update to EXIT_FAILURE
    }

    const char *filename = argv[1];
    printf("Processing file: %s\n", filename);

    ParseResult result = parse_file(filename);

    // Error
    if (result.error != PARSE_OK) {
        // Error messages are already logged by parse_file, exit here
        return 1;
    }

    // Success
    printf("\nFile Details\n");
    printf("- Lines: %d\n", result.line_count);
    printf("- Words: %d\n", result.word_count);
    printf("- Characters: %d\n", result.char_count);

    return 0;
}
