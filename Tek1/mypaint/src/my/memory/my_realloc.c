/*
** EPITECH PROJECT, 2023
** my_realloc.c
** File description:
** my_realloc.c
*/

#include "my/memory.h"

static size_t min(size_t size_a, size_t size_b)
{
    return size_a < size_b ? size_a : size_b;
}

void *my_realloc(void *ptr, size_t bytes)
{
    void *copy = my_malloc(bytes);

    if (ptr && (copy || !bytes)) {
        my_memmove(copy, ptr, min(*((size_t *)ptr - 1), bytes));
        my_free(ptr);
    }
    return copy;
}
