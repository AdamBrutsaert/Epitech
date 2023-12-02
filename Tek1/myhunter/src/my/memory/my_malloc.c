/*
** EPITECH PROJECT, 2022
** my_malloc.c
** File description:
** my_malloc.c
*/

#include "my.h"
#include <stdlib.h>

void *my_malloc(uint64_t n)
{
    void *ptr = malloc(n + sizeof(uint64_t));

    if (!ptr)
        return NULL;
    *(uint64_t*)ptr = n;
    return (uint64_t*)ptr + 1;
}
