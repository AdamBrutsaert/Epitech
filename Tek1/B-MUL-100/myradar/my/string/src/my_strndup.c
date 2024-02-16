/*
** EPITECH PROJECT, 2022
** my_strndup.c
** File description:
** my_strndup.c
*/

#include "my/string.h"

#include <my/memory.h>

char *my_strndup(char const *string, uint64_t n)
{
    char *copy = my_malloc(n + 1);

    if (copy) {
        my_strncpy(copy, string, n);
        copy[n] = '\0';
    }
    return copy;
}
