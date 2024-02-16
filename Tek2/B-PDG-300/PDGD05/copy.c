/*
** EPITECH PROJECT, 2024
** copy.c
** File description:
** copy.c
*/

#include "string.h"

#include <string.h>

size_t copy(const string_t *self, char *s, size_t n, size_t pos)
{
    size_t length;

    if (s == NULL || self->str == NULL)
        return 0;
    length = strlen(self->str);
    if (pos >= length)
        return 0;
    strncpy(s, self->str + pos, n);
    if (n > length - pos + 1)
        return length - pos + 1;
    return n;
}
