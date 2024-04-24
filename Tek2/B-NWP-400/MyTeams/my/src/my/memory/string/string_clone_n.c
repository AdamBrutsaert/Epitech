/*
** EPITECH PROJECT, 2024
** string_clone_n.c
** File description:
** string_clone_n.c
*/

#include "my/memory/string.h"

string_t *string_clone_n(const string_t *self, size_t n)
{
    size_t bytes = n > STRING_LEN(self) ? STRING_LEN(self) : n;

    return string_create_from_buffer(STRING_CDATA(self), bytes);
}
