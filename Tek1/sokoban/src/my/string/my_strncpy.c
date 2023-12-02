/*
** EPITECH PROJECT, 2022
** my_strncpy.c
** File description:
** my_strncpy.c
*/

#include "my/string.h"

char *my_strncpy(char *dest, char const *src, u64_t n)
{
    u64_t i = 0;

    for (; i < n && src[i]; i++)
        dest[i] = src[i];
    for (; i < n; i++)
        dest[i] = '\0';
    return dest;
}
