/*
** EPITECH PROJECT, 2022
** my_strncpy.c
** File description:
** my_strncpy.c
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, uint64_t n)
{
    uint64_t i = 0;

    for (; i < n && src[i]; i++)
        dest[i] = src[i];
    for (; i < n; i++)
        dest[i] = '\0';
    return dest;
}
