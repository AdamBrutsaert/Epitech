/*
** EPITECH PROJECT, 2022
** my_strhash.c
** File description:
** my_strhash.c
*/

#include "my/string.h"

uint64_t my_strhash(char const *string)
{
    uint64_t hash = 5381;

    for (; *string; string++)
        hash = ((hash << 5) + hash) + *string;
    return hash;
}
