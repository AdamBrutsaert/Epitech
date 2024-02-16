/*
** EPITECH PROJECT, 2023
** string.c
** File description:
** string.c
*/

#include "string.h"

#include <stdlib.h>

char *my_strndup(char const *string, uint64_t bytes)
{
    char *copy = malloc((bytes + 1) * sizeof(char));

    for (uint64_t i = 0; i < bytes; i++)
        copy[i] = string[i];
    copy[bytes] = '\0';
    return copy;
}

static int8_t compare_characters(char a, char b)
{
    if (a >= 'A' && a <= 'Z')
        a += 'a' - 'A';
    if (b >= 'A' && b <= 'Z')
        b += 'a' - 'A';
    return a - b;
}

int16_t my_strcmp(char const *s1, char const *s2)
{
    uint64_t i = 0;

    while (s1[i] && s2[i] && !compare_characters(s1[i], s2[i]))
        i++;
    return compare_characters(s1[i], s2[i]);
}

uint64_t my_strlen(char const *string)
{
    uint64_t length = 0;

    while (string[length])
        length++;
    return length;
}
