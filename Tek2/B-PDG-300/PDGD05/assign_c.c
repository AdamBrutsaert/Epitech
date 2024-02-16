/*
** EPITECH PROJECT, 2024
** assign_c.c
** File description:
** assign_c.c
*/

#include "string.h"

#include <stdlib.h>

void assign_c(string_t *self, const char *str)
{
    if (self->str != NULL)
        free(self->str);
    string_init(self, str);
}
