/*
** EPITECH PROJECT, 2024
** clear.c
** File description:
** clear.c
*/

#include "string.h"

#include <stdlib.h>

void clear(string_t *self)
{
    if (self->str != NULL)
        self->str[0] = '\0';
}
