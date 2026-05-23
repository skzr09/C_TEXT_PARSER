# README

A simple C project that parses text files, counts lines/words, and demonstrates structured project organization with logging, modularization, and testing.

## Covers
Project covers basics:

- Structure
- Documentation
- Cmake
- Logging
- CTest

## Structure
```
C_TEXT_PARSER
|
├── src/
|   ├── main.c    # entry point
|   ├── parser.c
|   ├── logger.c
|
├── build/
├── data/
|   ├── sample.txt
|   ├── empty.txt
|
├── tests/
|   ├── test_parser.c
|
├── include/
|   ├── parser.h
|   ├──  logger.h
|
├── CMakeLists.txt
├── LICENSE
├── README.md

```

## Build Instructions
```
cmake -S . -B build
cmake --build build
```

## Run Instructions
```
# Run main parser
./build/parser data/sample.txt

# Run tests directly
./build/test_parser

# Or run all tests via CTest
cd build
ctest --output-on-failure
```
