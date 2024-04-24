/*
** EPITECH PROJECT, 2024
** string_clone.c
** File description:
** string_clone.c
*/

#include "my/memory/string.h"

string_t *string_clone(const string_t *self)
{
    return string_create_from_buffer(STRING_CDATA(self), STRING_LEN(self));
}
