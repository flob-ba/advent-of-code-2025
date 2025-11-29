#include "array_list.h"

#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 1
#define GROWTH_FACTOR 2

void* _create_array_list(size_t stride) {
    array_list_header* header = malloc(sizeof(array_list_header) + INITIAL_CAPACITY * stride);
    memset(header, 0, sizeof(array_list_header) + INITIAL_CAPACITY * stride);

    header->capacity = INITIAL_CAPACITY;
    header->length = 0;
    header->stride = stride;

    return (void*)(header + 1);
}

void destroy_array_list(void* self) {
    assert(self != NULL);
    array_list_header* header = (array_list_header*)self - 1;
    free(header);
}

size_t array_list_get_capacity(void* self) {
    assert(self != NULL);
    array_list_header* header = (array_list_header*)self - 1;
    return header->capacity;
}

size_t array_list_get_length(void* self) {
    assert(self != NULL);
    array_list_header* header = (array_list_header*)self - 1;
    return header->length;
}

void* _array_list_reserve(void* self, size_t new_min_capacity) {
    assert(self != NULL);
    array_list_header* header = (array_list_header*)self - 1;

    if (new_min_capacity <= header->capacity) {
        return self;
    }

    size_t new_capacity = header->capacity;
    while (new_min_capacity > new_capacity) {
        new_capacity *= GROWTH_FACTOR;
    }

    array_list_header* new_header = malloc(sizeof(array_list_header) + new_capacity * header->stride);
    memset(new_header, 0, sizeof(array_list_header) + new_capacity * header->stride);
    memcpy(new_header, header, sizeof(array_list_header) + header->length * header->stride);
    new_header->capacity = new_capacity;

    free(header);

    return (void*)(new_header + 1);
}

void* _array_list_push(void* self, void* elem) {
    assert(self != NULL);

    array_list_header* header = (array_list_header*)self - 1;
    self = _array_list_reserve(self, header->length + 1);
    header = (array_list_header*)self - 1;

    memcpy((int8_t*)(header + 1) + header->stride * header->length, elem, header->stride);
    ++header->length;

    return self;
}

void* _array_list_insert(void* self, size_t position, void* elem) {
    assert(self != NULL);

    array_list_header* header = (array_list_header*)self - 1;
    assert(position <= header->length);

    self = _array_list_reserve(self, header->length + 1);
    header = (array_list_header*)self - 1;

    memmove((int8_t*)(header + 1) + header->stride * (position + 1), (int8_t*)(header + 1) + header->stride * position, (header->length - position) * header->stride);
    memcpy((int8_t*)(header + 1) + header->stride * position, elem, header->stride);
    ++header->length;

    return self;
}

void array_list_erase(void* self, size_t position) {
    assert(self != NULL);

    array_list_header* header = (array_list_header*)self - 1;
    assert(position < header->length);

    memmove((int8_t*)(header + 1) + header->stride * position, (int8_t*)(header + 1) + header->stride * (position + 1), (header->length - position) * header->stride);
    --header->length;
}
