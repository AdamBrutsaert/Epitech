/*
** EPITECH PROJECT, 2022
** strict_str_to_i32.c
** File description:
** strict_str_to_i32.c
*/

#include "my/conversion.h"

// TODO: check overflow
status_t strict_str_to_i32(char const *string, i32_t *value)
{
    i8_t sign = 1;

    *value = 0;
    if (*string == '-') {
        sign = -1;
        string++;
    }
    for (; *string >= '0' && *string <= '9'; string++)
        *value = *value * 10 + sign * (*string - '0');
    return *string ? STATUS_ERROR : STATUS_SUCCESS;
}
