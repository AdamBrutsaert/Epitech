/*
** EPITECH PROJECT, 2022
** my_realloc.c
** File description:
** my_realloc.c
*/

#include "my.h"
#include <stdlib.h>

void *my_realloc(void *src, uint64_t n)
{
    void *dest = my_malloc(n);

    if (dest && src) {
        my_memmove(dest, src, my_u64_min(n, my_memlen(src)));
        my_free(src);
    }
    return dest;
}
