#include "string.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 1
#define GROWTH_FACTOR 2

char* create_string() {
    string_header* header = malloc(sizeof(string_header) + INITIAL_CAPACITY + 1);
    memset(header, 0, sizeof(string_header) + INITIAL_CAPACITY + 1);

    header->capacity = INITIAL_CAPACITY;
    header->length = 0;

    return (char*)(header + 1);
}

void destroy_string(char* self) {
    assert(self != NULL);
    string_header* header = (string_header*)self - 1;
    free(header);
}

size_t string_get_capacity(const char* self) {
    assert(self != NULL);
    string_header* header = (string_header*)self - 1;
    return header->capacity;
}

size_t string_get_length(const char* self) {
    assert(self != NULL);
    string_header* header = (string_header*)self - 1;
    return header->length;
}

char* _string_reserve(char* self, size_t new_min_capacity) {
    assert(self != NULL);
    string_header* header = (string_header*)self - 1;

    if (new_min_capacity <= header->capacity) {
        return self;
    }

    size_t new_capacity = header->capacity;
    while (new_min_capacity > new_capacity) {
        new_capacity *= GROWTH_FACTOR;
    }

    string_header* new_header = malloc(sizeof(string_header) + new_capacity + 1);
    memset(new_header, 0, sizeof(string_header) + new_capacity + 1);
    memcpy(new_header, header, sizeof(string_header) + header->length);
    new_header->capacity = new_capacity;

    free(header);

    return (char*)(new_header + 1);
}

char* _string_push(char* self, char c) {
    assert(self != NULL);

    string_header* header = (string_header*)self - 1;
    self = _string_reserve(self, header->length + 1);
    header = (string_header*)self - 1;

    self[header->length] = c;
    ++header->length;

    return self;
}

char* _string_insert(char* self, size_t position, char c) {
    assert(self != NULL);

    string_header* header = (string_header*)self - 1;
    assert(position <= header->length);

    self = _string_reserve(self, header->length + 1);
    header = (string_header*)self - 1;

    memmove((char*)(header + 1) + position + 1, (char*)(header + 1) + position, header->length - position);
    self[position] = c;
    ++header->length;

    return self;
}

void string_erase(char* self, size_t position) {
    assert(self != NULL);

    string_header* header = (string_header*)self - 1;
    assert(position < header->length);

    memmove((char*)(header + 1) + position, (char*)(header + 1) + position + 1, header->length - position);
    --header->length;
}
