/*
** EPITECH PROJECT, 2022
** my_strdup
** File description:
** Implementation of my_strdup
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    char *str = malloc(sizeof(char) * (my_strlen(src) + 1));

    if (str != 0)
        my_strcpy(str, src);
    return str;
}
