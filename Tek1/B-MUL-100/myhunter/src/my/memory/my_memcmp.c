/*
** EPITECH PROJECT, 2022
** my_memcmp.c
** File description:
** my_memcmp.c
*/

#include "my.h"

int8_t my_memcmp(void *a, void *b, uint64_t n)
{
    uint64_t i = 0;

    for (; i < n; i++) {
        if (((char*)a)[i] != ((char*)b)[i])
            break;
    }
    if (i == n)
        return 0;
    if (((unsigned char *)a)[i] - ((unsigned char *)b)[i] < 0)
        return -1;
    return 1;
}
