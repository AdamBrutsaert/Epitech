/*
** EPITECH PROJECT, 2024
** split_s.c
** File description:
** split_s.c
*/

#include "string.h"

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static bool get_next_word(string_t **str, char **string, char separator)
{
    char *begin = *string;
    char *end = *string;
    char *dup = NULL;

    *str = malloc(sizeof(string_t));
    if (str == NULL)
        return false;
    while (*end != separator && *end != '\0')
        end++;
    *string = *end == '\0' ? end : end + 1;
    dup = strndup(begin, end - begin);
    if (dup == NULL) {
        free(str);
        return false;
    }
    string_init(*str, dup);
    free(dup);
    return true;
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

static void free_array(string_t **array)
{
    for (size_t i = 0; array[i]; i++)
        free(array[i]->str);
    free(array);
}

static string_t **do_split(char *string, char separator)
{
    size_t count = count_words(string, separator);
    string_t **array = malloc(sizeof(string_t *) * (count + 1));

    if (string == NULL || array == NULL) {
        free(string);
        free(array);
        return NULL;
    }
    for (size_t i = 0; i < count; i++) {
        if (!get_next_word(&array[i], &string, separator)) {
            free_array(array);
            return NULL;
        }
    }
    array[count] = NULL;
    return array;
}

string_t **split_s(const string_t *self, char separator)
{
    if (self->str == NULL)
        return NULL;
    return do_split(self->str, separator);
}
