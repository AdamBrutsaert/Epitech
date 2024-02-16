/*
** EPITECH PROJECT, 2022
** my_memmove.c
** File description:
** Implementation of my_memmove
*/

#include "my.h"

void *my_memmove(void *dest, void const *src, long n)
{
    if (src >= dest) {
        for (long i = 0; i < n; i++)
            ((char *) dest)[i] = ((char const *) src)[i];
    } else {
        for (long i = 0; i < n; i++)
            ((char *) dest)[n - 1 - i] = ((char const *) src)[n - 1 - i];
    }
    return dest;
}
