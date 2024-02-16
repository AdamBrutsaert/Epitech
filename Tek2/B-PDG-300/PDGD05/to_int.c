/*
** EPITECH PROJECT, 2024
** to_int.c
** File description:
** to_int.c
*/

#include "string.h"

#include <stdlib.h>

int to_int(const string_t *self)
{
    if (self->str == NULL)
        return 0;
    return atoi(self->str);
}
