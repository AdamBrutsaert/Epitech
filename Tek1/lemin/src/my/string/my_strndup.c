/*
** EPITECH PROJECT, 2023
** my_strndup.c
** File description:
** my_strndup.c
*/

#include "my/string.h"

#include <stdlib.h>

char *my_strndup(const char *str, size_t bytes)
{
    char *dup = malloc(bytes + 1);

    if (dup == NULL)
        return NULL;
    my_strncpy(dup, str, bytes);
    dup[bytes] = '\0';
    return dup;
}
