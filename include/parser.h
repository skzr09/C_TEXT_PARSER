#ifndef PARSER_H
#define PARSER_H

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
