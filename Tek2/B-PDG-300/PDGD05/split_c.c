/*
** EPITECH PROJECT, 2024
** split_c.c
** File description:
** split_c.c
*/

#include "string.h"

#include <stdlib.h>
#include <string.h>

static char *get_next_word(char **string, char separator)
{
    char *begin = *string;
    char *end = *string;

    while (*end != separator && *end != '\0')
        end++;
    *string = *end == '\0' ? end : end + 1;
    return strndup(begin, end - begin);
}

static size_t count_words(char *string, char separator)
{
    size_t count = 1;

    for (; *string; string++) {
        if (*string == separator)
            count++;
    }
    return count;
}

static void free_array(char **array)
{
    for (size_t i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}

static char **do_split(char *string, char separator)
{
    size_t count = count_words(string, separator);
    char **array = malloc(sizeof(char *) * (count + 1));

    if (string == NULL || array == NULL) {
        free(string);
        free(array);
        return NULL;
    }
    for (size_t i = 0; i < count; i++) {
        array[i] = get_next_word(&string, separator);
        if (array[i] == NULL) {
            free_array(array);
            return NULL;
        }
    }
    array[count] = NULL;
    return array;
}

char **split_c(const string_t *self, char separator)
{
    if (self->str == NULL)
        return NULL;
    return do_split(self->str, separator);
}
