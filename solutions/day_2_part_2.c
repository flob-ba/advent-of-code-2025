#include "solution.h"

#include "aoc_util/string.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

uint64_t solve_day_2_part_2(const puzzle_input* puzzle_input) {
    uint64_t result = 0;

    const char* line = puzzle_input->lines[0];

    size_t start_position = 0;
    size_t end_position;

    while (start_position < string_get_length(line)) {
        uint64_t start_range;
        uint64_t end_range;

        string_find(line, '-', start_position, &end_position);
        char* substring = string_substring(line, start_position, end_position - 1);
        start_range = atoll(substring);
        destroy_string(substring);
        start_position = end_position + 1;

        if (!string_find(line, ',', start_position, &end_position)) {
            end_position = string_get_length(line);
        }
        substring = string_substring(line, start_position, end_position - 1);
        end_range = atoll(substring);
        destroy_string(substring);
        start_position = end_position + 1;

        for (uint64_t i = start_range; i <= end_range; ++i) {
            bool is_invalid = false;
            uint64_t digits_count = (uint64_t)log10(i) + 1;
            for (uint64_t sub_digit_count = 1; sub_digit_count <= digits_count / 2; ++sub_digit_count) {
                if (digits_count % sub_digit_count != 0)
                    continue;

                uint64_t sub = i / (uint64_t)pow(10, digits_count - sub_digit_count);
                uint64_t test = sub;
                uint64_t test_digit_count = sub_digit_count;
                while (test_digit_count < digits_count) {
                    test = (uint64_t)pow(10, sub_digit_count) * test + sub;
                    test_digit_count += sub_digit_count;
                }
                is_invalid = test == i;
                if (is_invalid) {
                    break;
                }
            }
            if (is_invalid) {
                result += i;
                continue;
            }
        }
    }
    return result;
}
