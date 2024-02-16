/*
** EPITECH PROJECT, 2022
** my_malloc.c
** File description:
** my_malloc.c
*/

#include "my/memory/allocation.h"

#include <stdlib.h>

void *my_malloc(uint64_t bytes)
{
    void *ptr;

    if (bytes == 0)
        return NULL;
    ptr = malloc(bytes + sizeof(uint64_t));
    if (!ptr)
        return NULL;
    *(uint64_t *)ptr = bytes;
    return (uint64_t *)ptr + 1;
}
