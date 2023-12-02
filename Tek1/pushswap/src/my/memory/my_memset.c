/*
** EPITECH PROJECT, 2022
** my_memset.c
** File description:
** my_memset.c
*/

#include "my/memory.h"

void *my_memset(void *dest, i8_t value, u64_t n)
{
    for (; n; n--)
        ((i8_t*)dest)[n - 1] = value;
    return dest;
}
