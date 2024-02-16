/*
** EPITECH PROJECT, 2023
** my_arrlen.c
** File description:
** my_arrlen.c
*/

#include "my/memory.h"

size_t my_arrlen(void *array)
{
    size_t length = 0;
    void **arr = array;

    while (arr[length])
        length++;
    return length;
}
