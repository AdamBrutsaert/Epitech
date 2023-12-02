/*
** EPITECH PROJECT, 2023
** my_freearr.c
** File description:
** my_freearr.c
*/

#include "my/memory.h"

#include <stdlib.h>

void my_freearr(void *array)
{
    void **arr = array;

    for (size_t i = 0; arr[i]; i++)
        free(arr[i]);
    free(arr);
}
