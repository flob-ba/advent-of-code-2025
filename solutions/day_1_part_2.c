#include "solution.h"

#include "aoc_util/array_list.h"

#include <stdlib.h>

uint64_t solve_day_1_part_2(const puzzle_input* puzzle_input) {
    uint8_t dial_position = 50;
    uint64_t counter = 0;
    for (size_t i = 0; i < array_list_get_length(puzzle_input->lines); ++i) {
        const char* line = puzzle_input->lines[i];
        uint16_t step = atoi(line + 1);
        if (line[0] == 'L') {
            for (uint16_t j = 0; j < step; ++j) {
                if (dial_position == 0) {
                    dial_position = 99;
                } else {
                    --dial_position;
                }
                if (dial_position == 0) {
                    ++counter;
                }
            }
        } else {
            for (uint16_t j = 0; j < step; ++j) {
                if (dial_position == 99) {
                    dial_position = 0;
                } else {
                    ++dial_position;
                }
                if (dial_position == 0) {
                    ++counter;
                }
            }
        }
    }

    return counter;
}
