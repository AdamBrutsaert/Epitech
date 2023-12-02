/*
** EPITECH PROJECT, 2022
** my_realloc.c
** File description:
** my_realloc.c
*/

#include "my/memory.h"

#include <stdlib.h>

static uint64_t min(uint64_t a, uint64_t b)
{
    return a < b ? a : b;
}

void *my_realloc(void *src, uint64_t new_length, uint64_t prev_length)
{
    void *copy = malloc(new_length);

    if (copy && src) {
        my_memmove(copy, src, min(prev_length, new_length));
        free(src);
    }
    return copy;
}
