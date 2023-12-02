/*
** EPITECH PROJECT, 2022
** my_realloc.c
** File description:
** Implementation of my_realloc
*/

#include <stdlib.h>

#include "my.h"

static uint32_t min(uint32_t a, uint32_t b)
{
    return a < b ? a : b;
}

void *my_realloc(void *src, uint32_t new_length, uint32_t length)
{
    void *copy = malloc(new_length);

    if (copy && src) {
        my_memmove(copy, src, min(length, new_length));
        free(src);
    }
    return copy;
}
