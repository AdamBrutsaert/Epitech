/*
** EPITECH PROJECT, 2023
** my_strndup.c
** File description:
** my_strndup.c
*/

#include "my/string.h"

#include <stdlib.h>

char *my_strndup(char const *string, size_t bytes)
{
    char *copy = malloc((bytes + 1) * sizeof(char));

    if (copy == NULL)
        return NULL;
    copy[bytes] = '\0';
    return my_strncpy(copy, string, bytes);
}
