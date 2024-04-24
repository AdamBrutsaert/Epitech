/*
** EPITECH PROJECT, 2024
** cstr_array_contains_help.c
** File description:
** cstr_array_contains_help.c
*/

#include "my/memory/cstr.h"

#include <string.h>

bool cstr_array_contains_help(char **array)
{
    for (; *array != nullptr; array++) {
        if (strcmp(*array, "-help") == 0)
            return true;
    }
    return false;
}
