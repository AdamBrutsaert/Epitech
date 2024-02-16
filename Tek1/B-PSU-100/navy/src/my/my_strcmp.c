/*
** EPITECH PROJECT, 2023
** my_strcmp.c
** File description:
** my_strcmp.c
*/

#include "my.h"

int16_t my_strcmp(char const *s1, char const *s2)
{
    uint64_t i = 0;

    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return s1[i] - s2[i];
}
