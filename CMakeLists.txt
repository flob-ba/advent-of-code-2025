cmake_minimum_required(VERSION 3.12)
project(aoc-25 LANGUAGES C)

add_executable(aoc-25)

target_compile_options(aoc-25 PRIVATE -Wall -Werror)
target_include_directories(aoc-25 PRIVATE ${CMAKE_SOURCE_DIR})
target_sources(aoc-25 PRIVATE
    main.c
    aoc_util/array_list.c
)

