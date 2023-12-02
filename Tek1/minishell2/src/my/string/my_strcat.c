/*
** EPITECH PROJECT, 2023
** my_strcat.c
** File description:
** my_strcat.c
*/

#include "my/string.h"

char *my_strcat(char *dest, char const *src)
{
    size_t length = my_strlen(dest);
    size_t i = 0;

    for (; src[i] != '\0'; i++)
        dest[length + i] = src[i];
    dest[length + i] = '\0';
    return dest;
}
