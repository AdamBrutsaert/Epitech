/*
** EPITECH PROJECT, 2023
** string_is_integer.c
** File description:
** string_is_integer.c
*/

#include "my/conversion.h"

bool string_is_integer(const char *string)
{
    if (*string == '-' || *string == '+')
        string++;
    while (*string >= '0' && *string <= '9')
        string++;
    return *string == '\0';
}
