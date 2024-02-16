/*
** EPITECH PROJECT, 2023
** my_strndup.c
** File description:
** my_strndup.c
*/

#include "my/string.h"

#include <stdlib.h>

char *my_strndup(const char *string, size_t n)
{
    char *dup = malloc(sizeof(char) * (n + 1));

    if (dup == NULL)
        return NULL;
    for (size_t i = 0; i < n; i++)
        dup[i] = string[i];
    dup[n] = '\0';
    return dup;
}
