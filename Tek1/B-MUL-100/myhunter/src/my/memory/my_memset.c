/*
** EPITECH PROJECT, 2022
** my_memset.c
** File description:
** my_memset.c
*/

#include "my.h"

void *my_memset(void *dest, int8_t value, uint64_t n)
{
    for (; n; n--)
        ((int8_t*)dest)[n - 1] = value;
    return dest;
}
