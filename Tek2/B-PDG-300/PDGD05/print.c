/*
** EPITECH PROJECT, 2024
** print.c
** File description:
** print.c
*/

#include "string.h"

#include <unistd.h>
#include <string.h>

void print(const string_t *self)
{
    if (self->str != NULL)
        write(STDOUT_FILENO, self->str, strlen(self->str));
}
