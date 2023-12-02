/*
** EPITECH PROJECT, 2022
** my_memmove.c
** File description:
** my_memmove.c
*/

#include "my/memory/operation.h"

void *my_memmove(void *dest, void const *src, uint64_t bytes)
{
    int8_t *ptr = dest;

    if (src >= dest) {
        for (uint64_t i = 0; i < bytes; i++)
            ptr[i] = ((int8_t const *)src)[i];
    } else {
        for (uint64_t i = 0; i < bytes; i++)
            ptr[bytes - 1 - i] = ((int8_t const *)src)[bytes - 1 - i];
    }
    return dest;
}
