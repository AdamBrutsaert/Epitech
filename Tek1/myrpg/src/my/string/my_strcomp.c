/*
** EPITECH PROJECT, 2023
** my_strcomp.c
** File description:
** my_strcomp.c
*/

#include "my/string.h"

int16_t my_strcmp(char const *s1, char const *s2)
{
    size_t i = 0;

    while (s1[i] && s1[i] == s2[i])
        i++;
    return s1[i] - s2[i];
}
