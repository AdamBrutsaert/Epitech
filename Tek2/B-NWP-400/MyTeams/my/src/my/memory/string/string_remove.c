/*
** EPITECH PROJECT, 2024
** string_remove.c
** File description:
** string_remove.c
*/

#include "my/memory/string.h"

void string_remove(string_t *self, size_t offset, size_t length)
{
    if (offset >= STRING_LEN(self))
        return;
    if (offset + length > STRING_LEN(self))
        length = STRING_LEN(self) - offset;
    vec_remove_some(self, offset, length);
}
