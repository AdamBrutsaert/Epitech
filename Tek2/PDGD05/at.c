/*
** EPITECH PROJECT, 2024
** at.c
** File description:
** at.c
*/

#include "string.h"

#include <string.h>

char at(const string_t *self, size_t pos)
{
    size_t length = self->str == NULL ? 0 : strlen(self->str);

    return pos >= length ? -1 : self->str[pos];
}
