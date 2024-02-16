/*
** EPITECH PROJECT, 2023
** my_strlen.c
** File description:
** my_strlen.c
*/

#include "my/string.h"

size_t my_strlen(char const *string)
{
    size_t length = 0;

    while (string[length])
        length++;
    return length;
}
