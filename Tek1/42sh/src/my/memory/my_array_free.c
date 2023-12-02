/*
** EPITECH PROJECT, 2023
** my_array_free.c
** File description:
** my_array_free.c
*/

#include "my/memory.h"

#include <stdlib.h>

void my_array_free(void *array)
{
    void **arr = array;

    if (array == NULL)
        return;
    for (size_t i = 0; arr[i] != NULL; i++)
        free(arr[i]);
    free(array);
}
