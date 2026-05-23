#include <stdio.h>
#include <ctype.h>
#include "parser.h"
#include "logger.h"


/* Tradeoff
 *  Having separate functions for counting lines, words, and characters is
 *  cleaner and more modular but it would require multiple passes through the file
 *  (one for each count - each function has a WHILE), which is inefficient.
 *
 *  Design choice: modularity over performance
 */

// count lines in file
int count_lines(FILE *fp) {
    int lines = 0;
    int c;
    while ((c = fgetc(fp)) != EOF) {
        if (c == '\n') lines++;
    }
    return lines;
}

// count words in file
int count_words(FILE *fp) {
    int words = 0;
    int c = 0;
    int in_word = 0; // flag to track if we're currently in a word

    while ((c = fgetc(fp)) != EOF) {
        if (isspace(c)) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            words++;
        }
    }
    return words;
}

// count characters in file
int count_chars(FILE *fp) {
    int chars = 0;
    while (fgetc(fp) != EOF) chars++;
    return chars;
}

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

    result.line_count = count_lines(fp);

    rewind(fp); // reset file pointer to beginning
    result.word_count = count_words(fp);

    rewind(fp);
    result.char_count = count_chars(fp);

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
