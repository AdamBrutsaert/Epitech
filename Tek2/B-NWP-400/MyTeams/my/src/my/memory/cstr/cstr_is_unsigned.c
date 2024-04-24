/*
** EPITECH PROJECT, 2024
** cstr_is_unsigned.c
** File description:
** cstr_is_unsigned.c
*/

#include "my/memory/cstr.h"

#include <ctype.h>

bool cstr_is_unsigned(const char *cstr)
{
    for (; *cstr != '\0'; cstr++) {
        if (!isdigit(*cstr))
            return false;
    }
    return true;
}
