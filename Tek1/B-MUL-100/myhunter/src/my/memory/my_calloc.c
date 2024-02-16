/*
** EPITECH PROJECT, 2022
** my_calloc.c
** File description:
** my_calloc.c
*/

#include "my.h"

void *my_calloc(uint64_t n)
{
    void *ptr = my_malloc(n);

    if (ptr)
        my_memset(ptr, 0, n);
    return ptr;
}
