/*
** EPITECH PROJECT, 2022
** my_strlen.c
** File description:
** my_strlen.c
*/

#include "my/string.h"

uint64_t my_strlen(char const *str)
{
    uint64_t length = 0;

    while (str[length])
        length++;
    return length;
}
