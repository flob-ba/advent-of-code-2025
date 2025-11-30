#include "puzzle_input.h"

#include "array_list.h"
#include "string.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

bool read_puzzle_input(puzzle_input* self, const char* filename) {
    assert(self != NULL);

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file \"%s\"\n", filename);
        return false;
    }

    self->lines = create_array_list(char*);

    while (1) {
        char c = fgetc(file);
        if (c == '\n') {
            array_list_push(self->lines, create_string());
            continue;
        } else if (c == EOF) {
            break;
        }
        char* line = create_string();
        string_push(line, c);
        while (1) {
            c = fgetc(file);
            if (c == EOF || c == '\n') {
                array_list_push(self->lines, line);
                break;
            }
            string_push(line, c);
        }
    }

    return true;
}

void destroy_puzzle_input(puzzle_input* self) {
    assert(self != NULL);
    for (size_t i = 0; i < array_list_get_length(self->lines); ++i) {
        destroy_string(self->lines[i]);
    }
    destroy_array_list(self->lines);
}
