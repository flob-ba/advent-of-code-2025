#include "solution.h"

#include "aoc_util/array_list.h"
#include "aoc_util/string.h"

#include <stdio.h>

uint64_t solve_day_3_part_2(const puzzle_input* puzzle_input) {
    uint64_t result = 0;
    for (size_t i = 0; i < array_list_get_length(puzzle_input->lines); ++i) {
        uint8_t* digits = create_array_list(uint8_t);
        array_list_reserve(digits, string_get_length(puzzle_input->lines[i]));
        for (size_t j = 0; j < string_get_length(puzzle_input->lines[i]); ++j) {
            array_list_push(digits, puzzle_input->lines[i][j] - '0');
        }

        uint8_t voltage_digits[12] = {0};
        size_t voltage_digits_positions[12] = {0};

        for (size_t j = 0; j < 12; ++j) {
            for (size_t k = voltage_digits_positions[j]; k < array_list_get_length(digits) - (11 - j); ++k) {
                if (digits[k] > voltage_digits[j]) {
                    voltage_digits[j] = digits[k];
                    voltage_digits_positions[j] = k;
                }
            }
            if (j < 11) {
                voltage_digits_positions[j + 1] = voltage_digits_positions[j] + 1;
            }
        }

        uint64_t voltage = 0;
        for (size_t j = 0; j < 12; ++j) {
            voltage = 10 * voltage + voltage_digits[j];
        }
        result += voltage;
    }
    return result;
}
