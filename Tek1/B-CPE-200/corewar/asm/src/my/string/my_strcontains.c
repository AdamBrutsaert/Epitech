/*
** EPITECH PROJECT, 2023
** my_strcontains.c
** File description:
** my_strcontains.c
*/

#include "my/string.h"

bool my_strcontains(const char *string, char character)
{
    for (size_t i = 0; string[i] != '\0'; i++)
        if (string[i] == character)
            return true;
    return false;
}
