/*
** EPITECH PROJECT, 2023
** my_memmove.c
** File description:
** my_memmove.c
*/

#include "my/memory.h"

void *my_memmove(void *dest, const void *src, size_t bytes)
{
    if (src >= dest) {
        for (size_t i = 0; i < bytes; i++)
            ((uint8_t *)dest)[i] = ((uint8_t const *)src)[i];
    } else {
        for (size_t i = 0; i < bytes; i++)
            ((uint8_t *)dest)[bytes - 1 - i] =
                ((uint8_t const *)src)[bytes - 1 - i];
    }
    return dest;
}
