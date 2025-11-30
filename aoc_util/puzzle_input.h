#ifndef _AOC_UTIL_PUZZLE_INPUT_H_
#define _AOC_UTIL_PUZZLE_INPUT_H_

#include <stdbool.h>
#include <stddef.h>

typedef struct puzzle_input {
    char** lines;
} puzzle_input;

bool read_puzzle_input(puzzle_input* self, const char* filename);
void destroy_puzzle_input(puzzle_input* self);

#endif
