/*
** EPITECH PROJECT, 2024
** string_split.c
** File description:
** string_split.c
*/

#include "my/memory/string.h"

vec_t *string_split(const string_t *self, char delimiter)
{
    vec_t *vec = vec_create(sizeof(string_t *));
    size_t start = 0;
    string_t *str;

    for (size_t end = 0; end < STRING_LEN(self); end++) {
        if (STRING_AT(self, end) != delimiter)
            continue;
        str = string_create_from_buffer(
            STRING_CDATA(self) + start,
            end - start
        );
        vec_push_back(vec, &str);
        start = end + 1;
    }
    str = string_create_from_buffer(
        STRING_CDATA(self) + start,
        STRING_LEN(self) - start
    );
    vec_push_back(vec, &str);
    return vec;
}
