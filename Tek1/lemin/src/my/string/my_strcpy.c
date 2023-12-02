/*
** EPITECH PROJECT, 2023
** my_strcpy.c
** File description:
** my_strcpy.c
*/

#include "my/string.h"

char *my_strcpy(char *dest, const char *src)
{
    size_t i = 0;

    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
