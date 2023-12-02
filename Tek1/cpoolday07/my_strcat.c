/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** Implementatio of my_strcat
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    my_strcpy(dest + my_strlen(dest), src);
    return dest;
}
