/*
** EPITECH PROJECT, 2024
** string_insert_cstr.c
** File description:
** string_insert_cstr.c
*/

#include "my/memory/string.h"

#include <string.h>

void string_insert_cstr(string_t *self, size_t offset, const char *cstr)
{
    if (offset > STRING_LEN(self))
        offset = STRING_LEN(self);
    vec_insert_some(self, offset, cstr, strlen(cstr));
}
