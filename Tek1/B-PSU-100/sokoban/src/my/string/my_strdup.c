/*
** EPITECH PROJECT, 2022
** my_strdup.c
** File description:
** my_strdup.c
*/

#include "my/string.h"
#include "my/memory.h"

char *my_strdup(char *string)
{
    char *copy = my_malloc(my_strlen(string) + 1);

    if (copy)
        my_strcpy(copy, string);
    return copy;
}
