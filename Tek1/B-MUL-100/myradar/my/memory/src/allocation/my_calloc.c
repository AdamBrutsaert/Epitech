/*
** EPITECH PROJECT, 2022
** my_calloc.c
** File description:
** my_calloc.c
*/

#include "my/memory/allocation.h"
#include "my/memory/operation.h"

void *my_calloc(uint64_t bytes)
{
    void *ptr = my_malloc(bytes);

    if (ptr)
        my_memset(ptr, 0, bytes);
    return ptr;
}
