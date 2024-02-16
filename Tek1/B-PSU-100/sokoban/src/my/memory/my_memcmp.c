/*
** EPITECH PROJECT, 2022
** my_memcmp.c
** File description:
** my_memcmp.c
*/

#include "my/memory.h"

i8_t my_memcmp(void *a, void *b, u64_t n)
{
    u64_t i = 0;

    for (; i < n; i++) {
        if (((i8_t *)a)[i] != ((i8_t *)b)[i])
            break;
    }
    if (i == n)
        return 0;
    if (((u8_t *)a)[i] - ((u8_t *)b)[i] < 0)
        return -1;
    return 1;
}
