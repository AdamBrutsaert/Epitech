/*
** EPITECH PROJECT, 2023
** conversion.c
** File description:
** conversion.c
*/

#include "my/conversion.h"

bool my_str_is_u64(char const *string)
{
    for (; *string; string++) {
        if (*string < '0' || *string > '9')
            return false;
    }
    return true;
}

uint64_t my_str_to_u64(char const *string)
{
    uint64_t number = 0;

    for (; *string; string++)
        number = number * 10 + (*string - '0');
    return number;
}

bool my_str_is_i64(char const *string)
{
    if (*string == '-')
        string++;
    for (; *string; string++) {
        if (*string < '0' || *string > '9')
            return false;
    }
    return true;
}

int64_t my_str_to_i64(char const *string)
{
    int8_t sign = 1;
    int64_t number = 0;

    if (*string == '-') {
        sign = -1;
        string++;
    }
    for (; *string; string++)
        number = number * 10 + sign * (*string - '0');
    return number;
}
