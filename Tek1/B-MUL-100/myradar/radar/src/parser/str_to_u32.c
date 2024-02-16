/*
** EPITECH PROJECT, 2022
** str_to_u32.c
** File description:
** str_to_u32.c
*/

#include "parser.h"

uint32_t str_to_u32(char const *string)
{
    uint32_t number = 0;

    for (; *string; string++)
        number = number * 10 + *string - '0';
    return number;
}
