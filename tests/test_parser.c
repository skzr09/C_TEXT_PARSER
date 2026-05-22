#include <stdio.h>
#include <assert.h>
#include "parser.h"

int main(void) {

    // Test 1: empty file
    ParseResult r1 = parse_file("../data/empty.txt");
    assert(r1.error == PARSE_ERR_EMPTY);

    // Test 2: normal file
    ParseResult r2 = parse_file("../data/sample.txt");
    assert(r2.error == PARSE_OK);
    assert(r2.line_count > 0);
    assert(r2.word_count > 0);

    // Test 3: non-existent file
    ParseResult r3 = parse_file("../data/missing.txt");
    assert(r3.error == PARSE_ERR_OPEN);

    printf("\x1b[32m✔ All tests passed!\x1b[0m\n"); // :)

    return 0;
}
