/*
** EPITECH PROJECT, 2022
** my_strcmp.c
** File description:
** my_strcmp.c
*/

#include "my/string.h"

int8_t my_strcmp(char const *s1, char const *s2)
{
    register short diff;

    while (*s1 && *s2) {
        if (*s1 != *s2)
            break;
        s1++;
        s2++;
    }
    diff = (unsigned char)(*s1) - (unsigned char)(*s2);
    return diff < 0 ? -1 : !!diff;
}
