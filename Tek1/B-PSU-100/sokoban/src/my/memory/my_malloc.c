/*
** EPITECH PROJECT, 2022
** my_malloc.c
** File description:
** my_malloc.c
*/

#include "my/memory.h"

#include <stdlib.h>

void *my_malloc(u64_t n)
{
    void *ptr = malloc(n + sizeof(u64_t));

    if (!ptr)
        return NULL;
    *(u64_t*)ptr = n;
    return (u64_t*)ptr + 1;
}
