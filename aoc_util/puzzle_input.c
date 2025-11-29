#include "puzzle_input.h"

#include "array_list.h"
#include "string.h"

#include <assert.h>
#include <stdio.h>

void destroy_puzzle_input(puzzle_input* self) {
    assert(self != NULL);
    for (size_t i = 0; i < array_list_get_length(*self); ++i) {
        destroy_string((*self)[i]);
    }
    destroy_array_list(*self);
}

puzzle_input read_puzzle_input(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file \"%s\"\n", filename);
        return NULL;
    }

    puzzle_input puzzle_input = create_array_list(char*);

    while (1) {
        char c = fgetc(file);
        if (c == '\n') {
            array_list_push(puzzle_input, create_string());
            continue;
        } else if (c == EOF) {
            break;
        }
        char* line = create_string();
        string_push(line, c);
        while (1) {
            c = fgetc(file);
            if (c == EOF || c == '\n') {
                array_list_push(puzzle_input, line);
                break;
            }
            string_push(line, c);
        }
    }

    return puzzle_input;
}

size_t puzzle_input_get_lines_count(const puzzle_input* self) {
    assert(self != NULL);
    return array_list_get_length(*self);
}
