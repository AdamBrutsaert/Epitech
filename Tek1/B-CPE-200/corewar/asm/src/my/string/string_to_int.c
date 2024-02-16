/*
** EPITECH PROJECT, 2023
** string_to_int.c
** File description:
** string_to_int.c
*/

#include "my/string_impl.h"

intmax_t string_to_int(string_t *string)
{
    intmax_t result = 0;
    int8_t sign = 1;
    size_t i = 0;

    if (string->length > 0 && string->value[i] == '-') {
        sign = -1;
        i++;
    }
    for (; i < string->length
            && string->value[i] >= '0' && string->value[i] <= '9'; i++)
        result = result * 10 + sign * (string->value[i] - '0');
    return result;
}
