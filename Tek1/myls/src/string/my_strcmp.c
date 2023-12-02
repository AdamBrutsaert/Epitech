/*
** EPITECH PROJECT, 2022
** my_strcmp.c
** File description:
** my_strcmp.c
*/

#include "my/string.h"

int32_t my_strcmp(char const *s1, char const *s2)
{
    while (*s1 && *s2) {
        if (*s1 != *s2)
            break;
        s1++;
        s2++;
    }
    return (unsigned char)(*s1) - (unsigned char)(*s2);
}
