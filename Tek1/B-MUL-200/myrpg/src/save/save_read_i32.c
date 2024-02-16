/*
** EPITECH PROJECT, 2023
** save_read_i32.c
** File description:
** save_read_i32.c
*/

#include "save_impl.h"

bool save_read_i32(char **buffer, int32_t *value)
{
    int8_t sign = 1;

    if (**buffer == '-') {
        sign = -1;
        *buffer += sizeof(char);
    }
    if (**buffer < '0' || **buffer > '9')
        return false;
    *value = 0;
    for (; **buffer >= '0' && **buffer <= '9'; *buffer += sizeof(char))
        *value = *value * 10 + **buffer - '0';
    *value *= sign;
    return true;
}
