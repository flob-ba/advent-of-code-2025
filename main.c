#include <stdio.h>

#include "aoc_util/puzzle_input.h"
#include "solutions/solution.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

const char* const INPUT_FILENAMES[12] = {
    "inputs/day_1.txt",
    "inputs/day_2.txt",
    "inputs/day_3.txt",
    "inputs/day_4.txt",
    "inputs/day_5.txt",
    "inputs/day_6.txt",
    "inputs/day_7.txt",
    "inputs/day_8.txt",
    "inputs/day_9.txt",
    "inputs/day_10.txt",
    "inputs/day_11.txt",
    "inputs/day_12.txt",
};
uint64_t solutions[24] = {0};

void solve(int8_t day, int8_t part) {
    fprintf(stdout, "Solving Day %d Part %d... ", day, part);
    fflush(stdout);

    int8_t index = 2 * (day - 1) + (part - 1);

    puzzle_input puzzle_input = {0};
    if (read_puzzle_input(&puzzle_input, INPUT_FILENAMES[day - 1])) {
        solutions[index] = SOLVE_PFNS[index](&puzzle_input);
        destroy_puzzle_input(&puzzle_input);
        fprintf(stdout, "\r");
    }
}

void solve_all() {
    for (int8_t day = 1; day <= 12; ++day) {
        solve(day, 1);
        solve(day, 2);
    }
}

void print_all_solutions() {
    printf(
        "                                   _____         _________   _______________   ________   .________\n"
        "                                  /  _  \\   ____ \\_   ___ \\  \\_____  \\   _  \\  \\_____  \\  |   ____/\n"
        "                                 /  /_\\  \\ /  _ \\/    \\  \\/   /  ____/  /_\\  \\  /  ____/  |____  \\\n"
        "                                /    |    (  <_> )     \\____ /       \\  \\_/   \\/       \\  /       \\\n"
        "                                \\____|__  /\\____/ \\______  / \\_______ \\_____  /\\_______ \\/______  /\n"
        "                                        \\/               \\/          \\/     \\/         \\/       \\/\n");

    for (int8_t i = 0; i < 4; ++i) {
        printf("+------------------------------");
    }
    printf("+\n");

    for (int8_t j = 0; j < 3; ++j) {
        for (int8_t i = 0; i < 4; ++i) {
            printf("|            Day %2d            ", 4 * j + i + 1);
        }
        printf("|\n");
        for (int8_t i = 0; i < 4; ++i) {
            printf("+--------+---------------------");
        }
        printf("+\n");
        for (int8_t i = 0; i < 4; ++i) {
            printf("| Part 1 | %19ld ", solutions[2 * (4 * j + i)]);
        }
        printf("|\n");
        for (int8_t i = 0; i < 4; ++i) {
            printf("| Part 2 | %19ld ", solutions[2 * (4 * j + i) + 1]);
        }
        printf("|\n");
        for (int8_t i = 0; i < 4; ++i) {
            printf("+--------+---------------------");
        }
        printf("+\n");
    }
}

int32_t main(int32_t argc, char* argv[]) {
    bool should_solve_all = true;

    if (argc == 2) {
        int8_t day = atoi(argv[1]);
        if (1 <= day && day <= 12) {
            should_solve_all = false;
            solve(day, 1);
            solve(day, 2);
            printf("Day %d - Part 1: %19ld\n", day, solutions[2 * (day - 1)]);
            printf("Day %d - Part 2: %19ld\n", day, solutions[2 * (day - 1) + 1]);
        }
    }

    if (argc == 3) {
        int8_t day = atoi(argv[1]);
        int8_t part = atoi(argv[2]);
        if (1 <= day && day <= 12 && (part == 1 || part == 2)) {
            should_solve_all = false;
            solve(day, part);
            if (part == 1) {
                printf("Day %d - Part 1: %19ld\n", day, solutions[2 * (day - 1)]);
            } else {
                printf("Day %d - Part 2: %19ld\n", day, solutions[2 * (day - 1) + 1]);
            }
        }
    }

    if (should_solve_all) {
        solve_all();
        print_all_solutions();
    }
}
