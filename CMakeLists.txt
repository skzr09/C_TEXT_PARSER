cmake_minimum_required(VERSION 3.10)
project(TextParser C)

# Use C99 standard
set(CMAKE_C_STANDARD 99)

# Include header files
include_directories(include)

# Add executable target
add_executable(parser
    src/main.c
    src/parser.c
)

# Add test executable target
add_executable(test_parser
    tests/test_parser.c
    src/parser.c
)

# support for cTest
enable_testing()
add_test(NAME ParserTests COMMAND test_parser)
