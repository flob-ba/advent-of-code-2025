#ifndef _AOC_UTIL_STRING_H_
#define _AOC_UTIL_STRING_H_

#include <stdbool.h>
#include <stddef.h>

typedef struct string_header {
    size_t capacity;
    size_t length;
} string_header;

char* create_string();
void destroy_string(char* self);

size_t string_get_capacity(const char* self);
size_t string_get_length(const char* self);

char* _string_reserve(char* self, size_t new_min_capacity);
#define string_reserve(self, new_min_capacity)          \
    {                                                   \
        self = _string_reserve(self, new_min_capacity); \
    }

char* _string_push(char* self, char c);
#define string_push(self, c)          \
    {                                 \
        self = _string_push(self, c); \
    }

char* _string_insert(char* self, size_t position, char c);
#define string_insert(self, position, c)          \
    {                                             \
        self = _string_insert(self, position, c); \
    }

void string_erase(char* self, size_t position);

bool string_find(const char* self, char target, size_t start_position, size_t* out_position);

char* string_substring(const char* self, size_t start_position, size_t end_position);

#endif
