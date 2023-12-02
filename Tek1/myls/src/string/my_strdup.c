/*
** EPITECH PROJECT, 2022
** my_strdup.c
** File description:
** my_strdup.c
*/

#include "my/string.h"

#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *str = malloc(sizeof(char) * (my_strlen(src) + 1));

    if (str != 0)
        my_strcpy(str, src);
    return str;
}
