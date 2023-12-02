/*
** EPITECH PROJECT, 2022
** my_realloc.c
** File description:
** Implementation of my_realloc
*/

#include "my.h"
#include <stdlib.h>

static unsigned int min(unsigned int a, unsigned int b)
{
    return a < b ? a : b;
}

void *my_realloc(void *src, unsigned int new_length, unsigned int length)
{
    void *copy = malloc(new_length);

    if (copy && src) {
        my_memmove(copy, src, min(length, new_length));
        free(src);
    }
    return copy;
}
