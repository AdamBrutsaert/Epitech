/*
** EPITECH PROJECT, 2024
** append_c.c
** File description:
** append_c.c
*/

#include "string.h"

#include <string.h>
#include <stdlib.h>

void append_c(string_t *self, const char *ap)
{
    char *tmp = NULL;

    if (ap == NULL)
        return;
    tmp = calloc(strlen(self->str) + strlen(ap) + 1, sizeof(char));
    if (tmp == NULL)
        return;
    strcat(tmp, self->str);
    strcat(tmp, ap);
    free(self->str);
    self->str = tmp;
}
