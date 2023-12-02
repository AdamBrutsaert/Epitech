/*
** EPITECH PROJECT, 2023
** my_memset.c
** File description:
** my_memset.c
*/

#include "my/memory.h"

void *my_memset(void *dest, uint8_t value, size_t bytes)
{
    for (size_t i = 0; i < bytes; i++)
        ((uint8_t *)dest)[i] = value;
    return dest;
}
