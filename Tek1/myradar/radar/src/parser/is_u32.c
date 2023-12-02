/*
** EPITECH PROJECT, 2022
** is_u32.c
** File description:
** is_u32.c
*/

#include "parser.h"

#include <my/string.h>

int8_t is_overflowing(char const *string)
{
    if (my_strlen(string) < 10)
        return 0;
    if (my_strlen(string) > 10)
        return 1;
    if (my_strcmp(string, "4294967295") > 0)
        return 1;
    return 0;
}

int8_t is_u32(char const *string)
{
    for (; *string; string++)
        if (*string < '0' || *string > '9')
            return 0;
    return !is_overflowing(string);
}
