/*
** EPITECH PROJECT, 2023
** my_strarrlen.c
** File description:
** my_strarrlen.c
*/

#include "my/string.h"

#include <stddef.h>

uint64_t my_strarrlen(char **array)
{
    uint64_t length = 0;

    while (array[length] != NULL)
        length++;
    return length;
}
