/*
** EPITECH PROJECT, 2022
** parser.c
** File description:
** Implementation of parser
*/

#include "rush3.h"
#include <stdlib.h>

static int retrieve_pattern_size(char *str, int *width, int *height)
{
    *width = 0;
    *height = 0;
    int error = 0;
    int other_width = -1;

    for (; *str && *str != '\n'; str++)
        (*width)++;
    for (; *str; str++) {
        if (*str == '\n') {
            error = other_width != *width && other_width != -1 ? 84 : error;
            other_width = 0;
            (*height)++;
        } else {
            other_width++;
        }
    }
    if (other_width > 0)
        error = 84;
    return error;
}

static char *alloc_empty_array(void)
{
    char *tokens = malloc(9);

    for (int i = 0; i < 9; i++)
        tokens[i] = ' ';
    return tokens;
}

static char *retrieve_tokens(char *tokens, char *str, int width, int height)
{
    if (width == 0 || height == 0)
        return tokens;
    tokens[0] = str[0];
    if (width > 2)
        tokens[1] = str[1];
    if (width > 1)
        tokens[2] = str[width - 1];
    if (height > 2)
        tokens[3] = str[width + 1];
    if (height > 2 && width > 1)
        tokens[4] = str[2 * width];
    if (height > 1)
        tokens[5] = str[(height - 1) * (width + 1)];
    if (height > 1 && width > 2)
        tokens[6] = str[(height - 1) * (width + 1) + 1];
    if (height > 1 && width > 1)
        tokens[7] = str[height * (width + 1) - 2];
    return tokens;
}

char *parse(char *str, int *width, int *height)
{
    char *tokens = alloc_empty_array();

    if (!retrieve_pattern_size(str, width, height))
        tokens = retrieve_tokens(tokens, str, *width, *height);
    return tokens;
}
