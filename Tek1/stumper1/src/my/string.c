/*
** EPITECH PROJECT, 2023
** string.c
** File description:
** string.c
*/

#include "my/string.h"

int16_t my_strcmp(char const *s1, char const *s2)
{
    uint64_t i = 0;

    while (s1[i] != '\0' && s1[i] == s2[i])
        i++;
    return s1[i] - s2[i];
}

int16_t my_strncmp(char const *s1, char const *s2, uint64_t bytes)
{
    uint64_t i = 0;

    while (s1[i] != '\0' && s1[i] == s2[i] && i + 1 < bytes)
        i++;
    return s1[i] - s2[i];
}

uint64_t my_strarrlen(char **array)
{
    uint64_t length = 0;

    if (!array)
        return 0;
    while (array[length] != 0)
        length++;
    return length;
}

uint64_t my_strlen(char const *string)
{
    uint64_t length = 0;

    while (string[length] != '\0')
        length++;
    return length;
}
