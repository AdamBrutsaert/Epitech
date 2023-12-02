/*
** EPITECH PROJECT, 2023
** my_malloc.c
** File description:
** my_malloc.c
*/

#include "my/memory.h"
#include "my/stdio.h"

#include <stdlib.h>

void *my_malloc(size_t bytes)
{
    void *ptr = malloc(bytes);

    if (ptr == NULL && bytes > 0) {
        my_eputcs("error: memory: failed to allocate.\n");
        exit(84);
    }
    return ptr;
}
