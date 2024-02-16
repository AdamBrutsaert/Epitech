/*
** EPITECH PROJECT, 2023
** save_read_char.c
** File description:
** save_read_char.c
*/

#include "save_impl.h"

bool save_read_char(char **buffer, char *value)
{
    if (**buffer == '\0')
        return false;
    *value = **buffer;
    *buffer += sizeof(char);
    return true;
}
