/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** Implementation of my_strlen
*/

#include "my.h"

int my_strlen(char const *string)
{
    int length = 0;

    while (string[length])
        length++;
    return length;
}
