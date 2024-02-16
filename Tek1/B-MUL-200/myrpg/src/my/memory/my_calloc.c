/*
** EPITECH PROJECT, 2023
** my_calloc.c
** File description:
** my_calloc.c
*/

#include "my/memory.h"

#include <stdlib.h>

void *my_calloc(size_t bytes)
{
    void *ptr = malloc(bytes);

    if (ptr == NULL)
        return NULL;
    my_memset(ptr, 0, bytes);
    return ptr;
}
