#include "solution.h"

#include "aoc_util/array_list.h"
#include "aoc_util/string.h"

#include <stdlib.h>
#include <string.h>

uint64_t solve_day_4_part_2(const puzzle_input* puzzle_input) {
    size_t row_count = array_list_get_length(puzzle_input->lines);
    size_t column_count = string_get_length(puzzle_input->lines[0]);

    char** rolls = malloc(column_count * sizeof(char*));
    for (size_t i = 0; i < row_count; ++i) {
        rolls[i] = malloc(row_count);
        memcpy(&rolls[i][0], puzzle_input->lines[i], column_count);
    }

    uint64_t result = 0;
    bool is_something_removed = true;

    while (is_something_removed) {
        is_something_removed = false;
        for (size_t i = 0; i < row_count; ++i) {
            for (size_t j = 0; j < column_count; ++j) {
                if (rolls[i][j] == '.')
                    continue;

                uint8_t adjacent_rolls_count = 0;

                bool has_space_above = i > 0;
                bool has_space_below = i < row_count - 1;
                bool has_space_left = j > 0;
                bool has_space_right = j < column_count - 1;

                if (has_space_above) {
                    if (has_space_left && rolls[i - 1][j - 1] == '@')
                        ++adjacent_rolls_count;
                    if (rolls[i - 1][j] == '@')
                        ++adjacent_rolls_count;
                    if (has_space_right && rolls[i - 1][j + 1] == '@')
                        ++adjacent_rolls_count;
                }
                if (has_space_left && rolls[i][j - 1] == '@')
                    ++adjacent_rolls_count;
                if (has_space_right && rolls[i][j + 1] == '@')
                    ++adjacent_rolls_count;
                if (has_space_below) {
                    if (has_space_left && rolls[i + 1][j - 1] == '@')
                        ++adjacent_rolls_count;
                    if (rolls[i + 1][j] == '@')
                        ++adjacent_rolls_count;
                    if (has_space_right && rolls[i + 1][j + 1] == '@')
                        ++adjacent_rolls_count;
                }

                if (adjacent_rolls_count < 4) {
                    rolls[i][j] = '.';
                    ++result;
                    is_something_removed = true;
                }
            }
        }
    }

    for (size_t i = 0; i < row_count; ++i) {
        free(rolls[i]);
    }
    free(rolls);

    return result;
}
