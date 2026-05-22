#ifndef PARSER_H
#define PARSER_H

// Enum for parsing errors
typedef enum {
    PARSE_OK = 0,        // success
    PARSE_ERR_OPEN = 1,  // cannot open file
    PARSE_ERR_EMPTY = 2, // file empty
    PARSE_ERR_CORRUPT = 3 // read error / corrupted
} ParseError;

// Struct to hold parsing results
typedef struct {
    // TODO: set the int (fixed-width types)
    int line_count;
    int word_count;
    int char_count;
    int error;   // 0 = success, 1 = error (e.g. file not found)
} ParseResult;

// parse file
ParseResult parse_file(const char *filename);

#endif // PARSER_H
