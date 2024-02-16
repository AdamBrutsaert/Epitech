/*
** EPITECH PROJECT, 2022
** my_memmove.c
** File description:
** my_memmove.c
*/

#include "my/memory.h"

void *my_memmove(void *dest, void const *src, uint64_t n)
{
    if (src >= dest) {
        for (uint64_t i = 0; i < n; i++)
            ((char *) dest)[i] = ((char const *) src)[i];
    } else {
        for (uint64_t i = 0; i < n; i++)
            ((char *) dest)[n - 1 - i] = ((char const *) src)[n - 1 - i];
    }
    return dest;
}
