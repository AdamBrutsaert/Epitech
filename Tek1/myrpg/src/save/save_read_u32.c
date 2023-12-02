/*
** EPITECH PROJECT, 2023
** save_read_u32.c
** File description:
** save_read_u32.c
*/

#include "save_impl.h"

bool save_read_u32(char **buffer, uint32_t *value)
{
    if (**buffer < '0' || **buffer > '9')
        return false;
    *value = 0;
    for (; **buffer >= '0' && **buffer <= '9'; *buffer += sizeof(char))
        *value = *value * 10 + **buffer - '0';
    return true;
}
