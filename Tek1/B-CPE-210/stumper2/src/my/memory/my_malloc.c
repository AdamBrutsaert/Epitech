/*
** EPITECH PROJECT, 2023
** my_malloc.c
** File description:
** my_malloc.c
*/

#include "my/memory.h"

#include <stdlib.h>

void *my_malloc(size_t bytes)
{
    size_t *ptr;

    if (bytes == 0)
        return NULL;
    ptr = malloc(bytes + sizeof(size_t));
    if (ptr == NULL)
        return NULL;
    *ptr = bytes;
    return ptr + 1;
}
