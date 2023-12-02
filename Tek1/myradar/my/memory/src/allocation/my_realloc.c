/*
** EPITECH PROJECT, 2022
** my_realloc.c
** File description:
** my_realloc.c
*/

#include "my/memory/allocation.h"
#include "my/memory/operation.h"

void *my_realloc(void *ptr, uint64_t bytes)
{
    void *dest = my_malloc(bytes);
    uint64_t length;

    if (ptr && dest) {
        length = *((uint64_t *)ptr - 1);
        my_memmove(dest, ptr, bytes < length ? bytes : length);
    }
    if (ptr && (dest || !bytes))
        my_free(ptr);
    return dest;
}
