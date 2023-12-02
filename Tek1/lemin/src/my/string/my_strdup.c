/*
** EPITECH PROJECT, 2023
** my_strdup.c
** File description:
** my_strdup.c
*/

#include "my/string.h"

#include <stdlib.h>

char *my_strdup(const char *src)
{
    char *dest = malloc(my_strlen(src) + 1);

    if (dest == NULL)
        return NULL;
    return my_strcpy(dest, src);
}
