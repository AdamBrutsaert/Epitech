/*
** EPITECH PROJECT, 2024
** assign_s.c
** File description:
** assign_s.c
*/

#include "string.h"

#include <stdlib.h>

void assign_s(string_t *self, const string_t *str)
{
    if (self->str != NULL)
        free(self->str);
    string_init(self, str == NULL ? NULL : str->str);
}
