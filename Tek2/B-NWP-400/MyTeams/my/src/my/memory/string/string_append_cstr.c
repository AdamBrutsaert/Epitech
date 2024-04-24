/*
** EPITECH PROJECT, 2024
** string_append_cstr.c
** File description:
** string_append_cstr.c
*/

#include "my/memory/string.h"

void string_append_cstr(string_t *self, const char *cstr)
{
    string_insert_cstr(self, STRING_LEN(self), cstr);
}
