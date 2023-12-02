/*
** EPITECH PROJECT, 2023
** split2.c
** File description:
** split2.c
*/

#include "string.h"

uint64_t split_length(char **array)
{
    uint64_t length = 0;

    while (array[length])
        length++;
    return length;
}
