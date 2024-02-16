/*
** EPITECH PROJECT, 2024
** compare_c.c
** File description:
** compare_c.c
*/

#include "string.h"

#include <string.h>

int compare_c(const string_t *self, const char *str)
{
    if (self->str == NULL && str == NULL)
        return 0;
    if (self->str == NULL)
        return -1;
    if (str == NULL)
        return 1;
    return strcmp(self->str, str);
}
