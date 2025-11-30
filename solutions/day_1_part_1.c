#include "solution.h"

#include "aoc_util/array_list.h"

#include <stdio.h>

uint64_t solve_day_1_part_1(const puzzle_input* puzzle_input) {
    printf("\n");

    for (size_t i = 0; i < array_list_get_length(puzzle_input->lines); ++i) {
        printf("%ld: %s\n", i, puzzle_input->lines[i]);
    }

    return 0;
}
