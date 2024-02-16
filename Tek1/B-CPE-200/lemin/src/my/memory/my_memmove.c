/*
** EPITECH PROJECT, 2023
** my_memmove.c
** File description:
** my_memmove.c
*/

#include "my/memory.h"

void *my_memmove(void *dest, const void *src, size_t bytes)
{
    int8_t *ptr = dest;

    if (src >= dest) {
        for (size_t i = 0; i < bytes; i++)
            ptr[i] = ((const int8_t *)src)[i];
    } else {
        for (size_t i = 0; i < bytes; i++)
            ptr[bytes - 1 - i] = ((const int8_t *)src)[bytes - 1 - i];
    }
    return dest;
}
