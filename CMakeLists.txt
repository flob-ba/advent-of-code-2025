cmake_minimum_required(VERSION 3.12)
project(aoc-25 LANGUAGES C)

add_executable(aoc-25)

target_compile_options(aoc-25 PRIVATE -Wall -Werror)
target_include_directories(aoc-25 PRIVATE ${CMAKE_SOURCE_DIR})
target_link_libraries(aoc-25 PRIVATE m)
target_sources(aoc-25 PRIVATE
    main.c
    aoc_util/array_list.c
    aoc_util/puzzle_input.c
    aoc_util/string.c
    solutions/solution.c
    solutions/day_1_part_1.c
    solutions/day_1_part_2.c
    solutions/day_2_part_1.c
    solutions/day_2_part_2.c
    solutions/day_3_part_1.c
    solutions/day_3_part_2.c
    solutions/day_4_part_1.c
    solutions/day_4_part_2.c
    solutions/day_5_part_1.c
    solutions/day_5_part_2.c
    solutions/day_6_part_1.c
    solutions/day_6_part_2.c
    solutions/day_7_part_1.c
    solutions/day_7_part_2.c
    solutions/day_8_part_1.c
    solutions/day_8_part_2.c
    solutions/day_9_part_1.c
    solutions/day_9_part_2.c
    solutions/day_10_part_1.c
    solutions/day_10_part_2.c
    solutions/day_11_part_1.c
    solutions/day_11_part_2.c
    solutions/day_12_part_1.c
    solutions/day_12_part_2.c
)

