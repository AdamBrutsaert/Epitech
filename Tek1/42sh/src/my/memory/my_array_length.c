/*
** EPITECH PROJECT, 2023
** my_array_length.c
** File description:
** my_array_length.c
*/

#include "my/memory.h"

size_t my_array_length(void *array)
{
    void **arr = array;
    size_t length = 0;

    while (arr[length] != NULL)
        length++;
    return length;
}
