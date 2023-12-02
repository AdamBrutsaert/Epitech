/*
** EPITECH PROJECT, 2022
** my_strdup.c
** File description:
** my_strdup.c
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(char const *string)
{
    char *copy = my_malloc(my_strlen(string) + 1);

    if (copy != NULL)
        my_strcpy(copy, string);
    return copy;
}
