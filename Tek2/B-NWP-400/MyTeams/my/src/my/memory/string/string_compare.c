/*
** EPITECH PROJECT, 2024
** string_compare.c
** File description:
** string_compare.c
*/

#include "my/memory/string.h"

#include <string.h>

int16_t string_compare(const string_t *self, const string_t *other)
{
    return strcmp(STRING_CDATA(self), STRING_CDATA(other));
}
