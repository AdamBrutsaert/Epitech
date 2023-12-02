/*
** EPITECH PROJECT, 2023
** split.c
** File description:
** split.c
*/

#include "split.h"
#include "string.h"

#include <stdint.h>
#include <stdlib.h>

static int8_t is_whitespace(char c)
{
    return c == ' ' || c == '\t';
}

static uint64_t get_words_count(char const *string)
{
    uint64_t count = 0;
    int8_t was_whitespace = 1;

    for (; *string; string++) {
        if (is_whitespace(*string))
            was_whitespace = 1;
        if (!is_whitespace(*string) && was_whitespace) {
            count++;
            was_whitespace = 0;
        }
    }
    return count;
}

static char *get_next_word(char const **string)
{
    char const *begin;

    while (**string && is_whitespace(**string))
        (*string)++;
    begin = *string;
    while (**string && !is_whitespace(**string))
        (*string)++;
    return my_strndup(begin, *string - begin);
}

char **split(char const *string)
{
    uint64_t words_count = get_words_count(string);
    char **array = malloc((words_count + 1) * sizeof(char *));

    for (uint64_t i = 0; i < words_count; i++)
        array[i] = get_next_word(&string);
    array[words_count] = 0;
    return array;
}

void split_free(char **array)
{
    for (uint64_t i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}
