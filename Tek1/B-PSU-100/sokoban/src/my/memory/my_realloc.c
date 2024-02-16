/*
** EPITECH PROJECT, 2022
** my_realloc.c
** File description:
** my_realloc.c
*/

#include "my/memory.h"
#include "my/math.h"

#include <stdlib.h>

void *my_realloc(void *ptr, u64_t n)
{
    void *dest = my_malloc(n);

    if (dest && ptr) {
        my_memmove(dest, ptr, my_u64_min(n, my_memlen(ptr)));
        my_free(ptr);
    }
    return dest;
}
