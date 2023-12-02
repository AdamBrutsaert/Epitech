/*
** EPITECH PROJECT, 2022
** my_strncmp.c
** File description:
** my_strncmp.c
*/

#include "my/string.h"

status_t my_strncmp(char const *s1, char const *s2, u64_t n)
{
    while (*s1 && *s2) {
        if (!n || *s1 != *s2)
            break;
        s1++;
        s2++;
        n--;
    }
    if (n && ((unsigned char)(*s1) - (unsigned char)(*s2)) < 0)
        return -1;
    return n && ((unsigned char)(*s1) - (unsigned char)(*s2));
}
