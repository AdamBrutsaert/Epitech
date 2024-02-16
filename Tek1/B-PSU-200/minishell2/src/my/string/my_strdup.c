/*
** EPITECH PROJECT, 2023
** my_strdup.c
** File description:
** my_strdup.c
*/

#include "my/string.h"

#include <stdlib.h>

char *my_strdup(char const *string)
{
    char *copy = malloc((my_strlen(string) + 1) * sizeof(char));

    if (copy == NULL)
        return NULL;
    return my_strcpy(copy, string);
}
