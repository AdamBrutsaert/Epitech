/*
** EPITECH PROJECT, 2022
** my_memset.c
** File description:
** my_memset.c
*/

#include "my/memory/operation.h"

void *my_memset(void *dest, int8_t value, uint64_t bytes)
{
    for (; bytes; bytes--)
        ((int8_t*)dest)[bytes - 1] = value;
    return dest;
}
