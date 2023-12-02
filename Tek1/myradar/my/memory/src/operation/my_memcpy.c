/*
** EPITECH PROJECT, 2022
** my_memcpy.c
** File description:
** my_memcpy.c
*/

#include "my/memory/operation.h"

void *my_memcpy(void *dest, void const *src, uint64_t bytes)
{
    for (uint64_t i = 0; i < bytes; i++)
        ((int8_t *)dest)[i] = ((int8_t const *)src)[i];
    return dest;
}
