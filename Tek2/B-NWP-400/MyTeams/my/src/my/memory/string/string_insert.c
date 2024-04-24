/*
** EPITECH PROJECT, 2024
** string_insert.c
** File description:
** string_insert.c
*/

#include "my/memory/string.h"

void string_insert(string_t *self, size_t offset, const string_t *other)
{
    if (offset > STRING_LEN(self))
        offset = STRING_LEN(self);
    vec_insert_some(self, offset, STRING_CDATA(other), STRING_LEN(other));
}
