/*
** EPITECH PROJECT, 2023
** my_strarrmove.c
** File description:
** my_strarrmove.c
*/

#include "my/string.h"

char **my_strarrmove(char **dest, char **src)
{
    uint64_t i = 0;
    for (; src[i] != 0; i++) {
        dest[i] = src[i];
        src[i] = 0;
    }
    dest[i] = 0;
    return dest;
}
