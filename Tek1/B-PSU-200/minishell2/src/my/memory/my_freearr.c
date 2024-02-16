/*
** EPITECH PROJECT, 2023
** my_freearr.c
** File description:
** my_freearr.c
*/

#include "my/memory.h"

#include <stdlib.h>

void my_freearr(void *arr)
{
    void **array = arr;

    if (array == NULL)
        return;
    for (size_t i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}
