/*
** EPITECH PROJECT, 2023
** my_strncmp.c
** File description:
** my_strncmp.c
*/

#include "my/string.h"

int16_t my_strncmp(char const *s1, char const *s2, size_t bytes)
{
    size_t i = 0;

    while (i + 1 < bytes && s1[i] != '\0' && s1[i] == s2[i])
        i++;
    return s1[i] - s2[i];
}
