/*
** EPITECH PROJECT, 2024
** string_compare_cstr.c
** File description:
** string_compare_cstr.c
*/

#include "my/memory/string.h"

#include <string.h>

int16_t string_compare_cstr(const string_t *self, const char *other)
{
    return strcmp(STRING_CDATA(self), other);
}
