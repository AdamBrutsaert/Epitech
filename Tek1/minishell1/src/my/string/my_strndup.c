/*
** EPITECH PROJECT, 2023
** my_strndup.c
** File description:
** my_strndup.c
*/

#include "my/string.h"
#include "my/error.h"

#include <stdlib.h>

char *my_strndup(char const *string, uint64_t bytes)
{
    char *copy = malloc(bytes + 1);

    if (copy == NULL)
        THROW_NULL(ERROR_ALLOCATION);
    for (uint64_t i = 0; i < bytes; i++)
        copy[i] = string[i];
    copy[bytes] = '\0';
    return copy;
}
