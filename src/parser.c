#include <stdio.h>
#include <ctype.h>
#include "parser.h"
#include "logger.h"

/**
 * Parses a text file and counts lines, words, and characters.
 *
 * @param filename Path to the file to parse
 * @return ParseResult struct with counts and error flag
 */
ParseResult parse_file(const char *filename) {

    ParseResult result = {0, 0, 0, 0};  // initialize all fields to 0

    FILE *fp = fopen(filename, "r");

    // Check if file was opened successfully
    if (!fp) {
        log_message(LOG_ERROR, "Failed to open file");
        result.error = PARSE_ERR_OPEN; // Set error flag, cannot open file
        return result;
    }
    log_message(LOG_INFO, "Parsing file");

    int c, in_word = 0;

    while ((c = fgetc(fp)) != EOF) {
        // fgetc returns int (next byte from file -> unsigned char -> integer)
        // c holds the ASCII code of the character
        // e.g., 'A' → 65, '\n' → 10

        result.char_count++;

        if (c == '\n') {
            result.line_count++;
        }

        if (isspace(c)) {
            in_word = 0;
        } else {
            if (!in_word) {
                result.word_count++;
                in_word = 1;
            }
        }
    }

    // Check if file is empty
    if (result.char_count == 0) {
        result.error = PARSE_ERR_EMPTY; // custom code for "empty file"
        log_message(LOG_WARN, "File is empty");
    }

    // Check if file read failed (corruption or I/O error)
    if (ferror(fp)) {
        result.error = PARSE_ERR_CORRUPT; // "corrupted file"
        log_message(LOG_ERROR, "Error reading file");
    }

    fclose(fp);
    return result;
}
