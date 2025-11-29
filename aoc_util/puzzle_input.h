#ifndef _AOC_UTIL_PUZZLE_INPUT_H_
#define _AOC_UTIL_PUZZLE_INPUT_H_

#include <stddef.h>

typedef char** puzzle_input;

void destroy_puzzle_input(puzzle_input* self);

puzzle_input read_puzzle_input(const char* filename);

size_t puzzle_input_get_lines_count(const puzzle_input* self);

#endif
