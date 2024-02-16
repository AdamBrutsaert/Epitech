/*
** EPITECH PROJECT, 2022
** str_to_i32.c
** File description:
** str_to_i32.c
*/

#include "my/conversion.h"

// TODO: check overflow
status_t str_to_i32(char const *string, i32_t *value)
{
    i8_t sign = 1;

    *value = 0;
    for (; *string == '-' || *string == '+'; string++)
        if (*string == '-')
            sign *= -1;
    for (; *string >= '0' && *string <= '9'; string++)
        *value = *value * 10 + sign * (*string - '0');
    return STATUS_SUCCESS;
}
