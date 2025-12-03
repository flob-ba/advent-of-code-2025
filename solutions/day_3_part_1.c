#include "solution.h"

#include "aoc_util/array_list.h"
#include "aoc_util/string.h"

#include <stdio.h>

uint64_t solve_day_3_part_1(const puzzle_input* puzzle_input) {
    uint64_t result = 0;
    for (size_t i = 0; i < array_list_get_length(puzzle_input->lines); ++i) {
        uint8_t* digits = create_array_list(uint8_t);
        array_list_reserve(digits, string_get_length(puzzle_input->lines[i]));
        for (size_t j = 0; j < string_get_length(puzzle_input->lines[i]); ++j) {
            array_list_push(digits, puzzle_input->lines[i][j] - '0');
        }

        size_t first_digit_position;
        uint8_t first_digit = 0;
        for (size_t j = 0; j < array_list_get_length(digits) - 1; ++j) {
            if (digits[j] > first_digit) {
                first_digit = digits[j];
                first_digit_position = j;
            }
        }

        uint8_t second_digit = 0;
        for (size_t j = first_digit_position + 1; j < array_list_get_length(digits); ++j) {
            if (digits[j] > second_digit) {
                second_digit = digits[j];
            }
        }
        result += 10 * first_digit + second_digit;
    }
    return result;
}
