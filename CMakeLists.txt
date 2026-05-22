cmake_minimum_required(VERSION 3.10)
project(TextParser C)

# Use C99 standard
set(CMAKE_C_STANDARD 99)

# Include header files
include_directories(include)

# Add executable target
add_executable(parser
    src/main.c
)
