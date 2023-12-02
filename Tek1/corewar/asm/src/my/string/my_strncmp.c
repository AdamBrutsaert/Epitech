/*
** EPITECH PROJECT, 2023
** my_strncmp.c
** File description:
** my_strncmp.c
*/

#include "my/string.h"

int16_t my_strncmp(const char *str1, const char *str2, size_t bytes)
{
    size_t i = 0;

    while (i + 1 < bytes && str1[i] != '\0' && str1[i] == str2[i])
        i++;
    return str1[i] - str2[i];
}
