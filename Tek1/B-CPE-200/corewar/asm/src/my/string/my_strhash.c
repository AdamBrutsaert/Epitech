/*
** EPITECH PROJECT, 2023
** my_strhash.c
** File description:
** my_strhash.c
*/

#include "my/string.h"

size_t my_strhash(const char *string)
{
    size_t hash = 5381;

    for (; *string; string++)
        hash = ((hash << 5) + hash) + *string;
    return hash;
}
