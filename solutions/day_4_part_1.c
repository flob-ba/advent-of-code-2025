#include "solution.h"

#include "aoc_util/array_list.h"
#include "aoc_util/string.h"

uint64_t solve_day_4_part_1(const puzzle_input* puzzle_input) {
    uint64_t result = 0;
    for (size_t i = 0; i < array_list_get_length(puzzle_input->lines); ++i) {
        for (size_t j = 0; j < string_get_length(puzzle_input->lines[i]); ++j) {
            if (puzzle_input->lines[i][j] == '.')
                continue;

            uint8_t adjacent_rolls_count = 0;

            bool has_space_above = i > 0;
            bool has_space_below = i < array_list_get_length(puzzle_input->lines) - 1;
            bool has_space_left = j > 0;
            bool has_space_right = j < string_get_length(puzzle_input->lines[i]) - 1;

            if (has_space_above) {
                if (has_space_left && puzzle_input->lines[i - 1][j - 1] == '@')
                    ++adjacent_rolls_count;
                if (puzzle_input->lines[i - 1][j] == '@')
                    ++adjacent_rolls_count;
                if (has_space_right && puzzle_input->lines[i - 1][j + 1] == '@')
                    ++adjacent_rolls_count;
            }
            if (has_space_left && puzzle_input->lines[i][j - 1] == '@')
                ++adjacent_rolls_count;
            if (has_space_right && puzzle_input->lines[i][j + 1] == '@')
                ++adjacent_rolls_count;
            if (has_space_below) {
                if (has_space_left && puzzle_input->lines[i + 1][j - 1] == '@')
                    ++adjacent_rolls_count;
                if (puzzle_input->lines[i + 1][j] == '@')
                    ++adjacent_rolls_count;
                if (has_space_right && puzzle_input->lines[i + 1][j + 1] == '@')
                    ++adjacent_rolls_count;
            }

            if (adjacent_rolls_count < 4) {
                ++result;
            }
        }
    }
    return result;
}
