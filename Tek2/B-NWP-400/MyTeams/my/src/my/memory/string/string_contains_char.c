/*
** EPITECH PROJECT, 2024
** string_contains_char.c
** File description:
** string_contains_char.c
*/

#include "my/memory/string.h"

bool string_contains_char(const string_t *self, char c)
{
    for (size_t i = 0; i < STRING_LEN(self); i++)
        if (STRING_AT(self, i) == c)
            return true;
    return false;
}
