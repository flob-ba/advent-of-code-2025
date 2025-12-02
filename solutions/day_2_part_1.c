#include "solution.h"

#include "aoc_util/string.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

uint64_t solve_day_2_part_1(const puzzle_input* puzzle_input) {
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
            uint64_t digits_count = (uint64_t)log10(i) + 1;
            if (digits_count % 2 == 1) {
                continue;
            }
            uint64_t first_half = i / (uint64_t)pow(10, digits_count / 2.0);
            uint64_t second_half = i - (uint64_t)pow(10, digits_count / 2.0) * first_half;
            if (first_half == second_half) {
                result += i;
            }
        }
    }
    return result;
}
