/*
** EPITECH PROJECT, 2023
** my_strsplit.c
** File description:
** my_strsplit.c
*/

#include "my/string.h"
#include "my/memory.h"

#include <stdlib.h>

static size_t count_elements(const char *string, char delimiter)
{
    size_t count = 1;

    for (; *string; string++) {
        if (*string == delimiter)
            count++;
    }
    return count;
}

static char *next_element(const char **string, char delimiter)
{
    const char *begin = *string;
    size_t length = 0;

    while (**string != delimiter && **string) {
        (*string)++;
        length++;
    }
    if (**string == delimiter)
        (*string)++;
    return my_strndup(begin, length);
}

char **my_strsplit(const char *string, char delimiter)
{
    size_t count = count_elements(string, delimiter);
    char **array = malloc(sizeof(char *) * (count + 1));

    if (array == NULL)
        return NULL;
    for (size_t i = 0; i < count; i++) {
        array[i] = next_element(&string, delimiter);
        if (array[i] == NULL) {
            my_freearr(array);
            return NULL;
        }
    }
    array[count] = NULL;
    return array;
}
