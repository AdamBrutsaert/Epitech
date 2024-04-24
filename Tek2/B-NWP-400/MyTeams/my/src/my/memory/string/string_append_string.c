/*
** EPITECH PROJECT, 2024
** string_append_string.c
** File description:
** string_append_string.c
*/

#include "my/memory/string.h"

void string_append_string(string_t *self, const string_t *other)
{
    string_append_cstr(self, STRING_CDATA(other));
}
