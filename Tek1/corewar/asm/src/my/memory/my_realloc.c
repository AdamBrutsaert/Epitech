/*
** EPITECH PROJECT, 2023
** my_realloc.c
** File description:
** my_realloc.c
*/

#include "my/memory.h"
#include "my/stdio.h"

#include <stdlib.h>

void *my_realloc(void *ptr, size_t bytes)
{
    void *new = realloc(ptr, bytes);

    if (new == NULL && bytes > 0) {
        my_eputcs("error: memory: failed to reallocate.\n");
        exit(84);
    }
    return new;
}
