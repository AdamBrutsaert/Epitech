/*
** EPITECH PROJECT, 2024
** insert_c.c
** File description:
** insert_c.c
*/

#include "string.h"

#include <stdlib.h>
#include <string.h>

void insert_c(string_t *self, size_t pos, const char *str)
{
    char *new;
    size_t len;

    if (self->str == NULL || str == NULL)
        return;
    len = strlen(self->str);
    if (pos > len)
        pos = len;
    new = calloc(strlen(self->str) + strlen(str) + 1, sizeof(char));
    strncpy(new, self->str, pos);
    new[pos] = '\0';
    strcat(new, str);
    strcat(new, self->str + pos);
    free(self->str);
    self->str = new;
}
