#include <stdio.h>
#include "parser.h"

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
    switch (result.error) {
        case PARSE_OK:
            printf("Lines: %d\nWords: %d\nChars: %d\n",
                result.line_count, result.word_count, result.char_count);
            break;
        case PARSE_ERR_OPEN:
            fprintf(stderr, "Error: cannot open file\n");
            break;
        case PARSE_ERR_EMPTY:
            fprintf(stderr, "Error: file is empty\n");
            break;
        case PARSE_ERR_CORRUPT:
            fprintf(stderr, "Error: file corrupted or read error\n");
            break;
    }

    // Success
    printf("\nFile Details\n");
    printf("- Lines: %d\n", result.line_count);
    printf("- Words: %d\n", result.word_count);
    printf("- Characters: %d\n", result.char_count);

    return 0;
}
