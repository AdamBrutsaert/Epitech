/*
** EPITECH PROJECT, 2024
** parse_args_from_string.c
** File description:
** parse_args_from_string.c
*/

#include "utils/parsing.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static bool is_whitespace(char c)
{
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

static size_t count_args(const char *buffer)
{
    size_t count = 0;
    size_t i = 0;

    while (is_whitespace(buffer[i]) && buffer[i])
        i++;
    while (buffer[i]) {
        count++;
        while (!is_whitespace(buffer[i]) && buffer[i])
            i++;
        while (is_whitespace(buffer[i]) && buffer[i])
            i++;
    }
    return count;
}

static char *next_argument(const char **buffer)
{
    const char *begin;

    while (is_whitespace(**buffer) && **buffer)
        (*buffer)++;
    begin = *buffer;
    while (!is_whitespace(**buffer) && **buffer)
        (*buffer)++;
    return strndup(begin, *buffer - begin);
}

char **parse_args_from_string(const char *string)
{
    size_t count = count_args(string);
    char **args = calloc(count + 1, sizeof(char *));

    if (args == NULL)
        return NULL;
    for (size_t i = 0; i < count; i++) {
        args[i] = next_argument(&string);
        if (args[i] == NULL) {
            free_args_array(args);
            return NULL;
        }
    }
    return args;
}
