#ifndef _SOLUTIONS_SOLUTION_H_
#define _SOLUTIONS_SOLUTION_H_

#include "aoc_util/puzzle_input.h"

#include <stdint.h>

uint64_t solve_day_1_part_1(const puzzle_input* puzzle_input);
uint64_t solve_day_1_part_2(const puzzle_input* puzzle_input);
uint64_t solve_day_2_part_1(const puzzle_input* puzzle_input);
uint64_t solve_day_2_part_2(const puzzle_input* puzzle_input);
uint64_t solve_day_3_part_1(const puzzle_input* puzzle_input);
uint64_t solve_day_3_part_2(const puzzle_input* puzzle_input);
uint64_t solve_day_4_part_1(const puzzle_input* puzzle_input);
uint64_t solve_day_4_part_2(const puzzle_input* puzzle_input);
uint64_t solve_day_5_part_1(const puzzle_input* puzzle_input);
uint64_t solve_day_5_part_2(const puzzle_input* puzzle_input);
uint64_t solve_day_6_part_1(const puzzle_input* puzzle_input);
uint64_t solve_day_6_part_2(const puzzle_input* puzzle_input);
uint64_t solve_day_7_part_1(const puzzle_input* puzzle_input);
uint64_t solve_day_7_part_2(const puzzle_input* puzzle_input);
uint64_t solve_day_8_part_1(const puzzle_input* puzzle_input);
uint64_t solve_day_8_part_2(const puzzle_input* puzzle_input);
uint64_t solve_day_9_part_1(const puzzle_input* puzzle_input);
uint64_t solve_day_9_part_2(const puzzle_input* puzzle_input);
uint64_t solve_day_10_part_1(const puzzle_input* puzzle_input);
uint64_t solve_day_10_part_2(const puzzle_input* puzzle_input);
uint64_t solve_day_11_part_1(const puzzle_input* puzzle_input);
uint64_t solve_day_11_part_2(const puzzle_input* puzzle_input);
uint64_t solve_day_12_part_1(const puzzle_input* puzzle_input);
uint64_t solve_day_12_part_2(const puzzle_input* puzzle_input);

typedef uint64_t (*solve_pfn)(const puzzle_input*);
extern const solve_pfn SOLVE_PFNS[24];

#endif
