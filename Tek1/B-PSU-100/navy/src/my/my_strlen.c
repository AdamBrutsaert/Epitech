/*
** EPITECH PROJECT, 2023
** my_strlen.c
** File description:
** my_strlen.c
*/

#include "my.h"

uint64_t my_strlen(char const *string)
{
    uint64_t length = 0;

    while (string[length])
        length++;
    return length;
}
