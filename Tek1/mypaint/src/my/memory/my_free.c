/*
** EPITECH PROJECT, 2023
** my_free.c
** File description:
** my_free.c
*/

#include "my/memory.h"

#include <stdlib.h>

void my_free(void *ptr)
{
    if (ptr == NULL)
        return;
    free((size_t *)ptr - 1);
}
