/*
** EPITECH PROJECT, 2023
** my_strlen.c
** File description:
** my_strlen.c
*/

#include "my/string.h"

size_t my_strlen(const char *string)
{
    size_t length = 0;

    while (string[length] != '\0')
        length++;
    return length;
}
