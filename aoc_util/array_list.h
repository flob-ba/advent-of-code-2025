#ifndef _AOC_UTIL_ARRAY_LIST_H_
#define _AOC_UTIL_ARRAY_LIST_H_

#include <stddef.h>

typedef struct array_list_header {
    size_t capacity;
    size_t length;
    size_t stride;
} array_list_header;

void* _create_array_list(size_t stride);
#define create_array_list(type) (type*)_create_array_list(sizeof(type))

void destroy_array_list(void* self);

size_t array_list_get_capacity(void* self);
size_t array_list_get_length(void* self);

void* _array_list_reserve(void* self, size_t new_min_capacity);
#define array_list_reserve(self, new_min_capacity)          \
    {                                                       \
        self = _array_list_reserve(self, new_min_capacity); \
    }

void* _array_list_push(void* self, void* elem);
#define array_list_push(self, elem)          \
    {                                        \
        typeof(elem) tmp = elem;             \
        self = _array_list_push(self, &tmp); \
    }

void* _array_list_insert(void* self, size_t position, void* elem);
#define array_list_insert(self, position, elem)          \
    {                                                    \
        typeof(elem) tmp = elem;                         \
        self = _array_list_insert(self, position, &tmp); \
    }

void array_list_erase(void* self, size_t position);

#endif
