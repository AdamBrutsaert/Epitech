/*
** EPITECH PROJECT, 2022
** my_memmove.c
** File description:
** my_memmove.c
*/

#include "my/memory.h"

void *my_memmove(void *dest, void const *src, u64_t n)
{
    if (src >= dest) {
        for (u64_t i = 0; i < n; i++)
            ((i8_t *)dest)[i] = ((i8_t const *)src)[i];
    } else {
        for (u64_t i = 0; i < n; i++)
            ((i8_t *)dest)[n - 1 - i] = ((i8_t const *)src)[n - 1 - i];
    }
    return dest;
}
