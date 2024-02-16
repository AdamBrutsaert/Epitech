/*
** EPITECH PROJECT, 2023
** string_to_integer.c
** File description:
** string_to_integer.c
*/

#include "my/conversion.h"

intmax_t string_to_integer(const char *string)
{
    intmax_t result = 0;
    int8_t sign = 1;

    if (*string == '-' || *string == '+') {
        sign -= 2 * (*string == '-');
        string++;
    }
    for (; *string >= '0' && *string <= '9'; string++)
        result = result * 10 + sign * (*string - '0');
    return result;
}
