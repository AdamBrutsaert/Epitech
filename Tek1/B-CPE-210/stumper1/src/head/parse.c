/*
** EPITECH PROJECT, 2023
** parse.c
** File description:
** parse.c
*/

#include "head.h"
#include "my/string.h"

static int parse(head_t *head, char *argument, char *next, bool *error)
{
    if (!my_strncmp(argument, "--", 2)) {
        head_parse_long(head, argument, error);
        return 0;
    }
    if (!my_strncmp(argument, "-", 1))
        return !!head_parse_short(head, argument, next, error);
    head_parse_arg(head, argument);
    return 0;
}

int head_parse(head_t *head, char **arguments)
{
    bool error = false;

    for (uint64_t i = 0; arguments[i]; i++) {
        arguments += parse(head, arguments[i], arguments[i + 1], &error);
    }
    return error ? 1 : 0;
}
