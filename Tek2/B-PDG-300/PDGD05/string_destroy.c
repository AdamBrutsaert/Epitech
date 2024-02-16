/*
** EPITECH PROJECT, 2024
** string_destroy.c
** File description:
** string_destroy.c
*/

#include "string.h"

#include <stdlib.h>

void string_destroy(string_t *self)
{
    free(self->str);
    self->str = NULL;
}
