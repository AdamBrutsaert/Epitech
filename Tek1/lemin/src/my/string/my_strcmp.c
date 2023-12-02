/*
** EPITECH PROJECT, 2023
** my_strcmp.c
** File description:
** my_strcmp.c
*/

#include "my/string.h"

int16_t my_strcmp(const char *s1, const char *s2)
{
    size_t i = 0;

    while (s1[i] && s1[i] == s2[i])
        i++;
    return s1[i] - s2[i];
}
