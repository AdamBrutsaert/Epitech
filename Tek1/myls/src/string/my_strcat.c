/*
** EPITECH PROJECT, 2022
** my_strcat.c
** File description:
** my_strcat.c
*/

#include "my/string.h"

char *my_strcat(char *dest, char const *src)
{
    my_strcpy(dest + my_strlen(dest), src);
    return dest;
}
