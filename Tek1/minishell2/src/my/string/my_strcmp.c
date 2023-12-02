/*
** EPITECH PROJECT, 2023
** my_strcmp.c
** File description:
** my_strcmp.c
*/

#include "my/string.h"

int16_t my_strcmp(char const *s1, char const *s2)
{
    size_t i = 0;

    while (s1[i] != '\0' && s1[i] == s2[i])
        i++;
    return s1[i] - s2[i];
}