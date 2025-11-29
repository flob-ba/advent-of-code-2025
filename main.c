#include <stdio.h>

#include "aoc_util/puzzle_input.h"

int main() {
    puzzle_input input = read_puzzle_input("inputs/day_1.txt");
    for (size_t i = 0; i < puzzle_input_get_lines_count(&input); ++i) {
        printf("%s\n", input[i]);
    }
    destroy_puzzle_input(&input);
}
