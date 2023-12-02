/*
** EPITECH PROJECT, 2022
** my_strcpy.c
** File description:
** my_strcpy.c
*/

#include "my/string.h"

char *my_strcpy(char *dest, char const *src)
{
    uint64_t i = 0;

    for (; src[i]; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
