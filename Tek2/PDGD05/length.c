/*
** EPITECH PROJECT, 2024
** length.c
** File description:
** length.c
*/

#include "string.h"

#include <string.h>

int length(const string_t *self)
{
    if (self->str == NULL)
        return -1;
    return strlen(self->str);
}
