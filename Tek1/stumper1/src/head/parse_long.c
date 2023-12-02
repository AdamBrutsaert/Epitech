/*
** EPITECH PROJECT, 2023
** parse_long.c
** File description:
** parse_long.c
*/

#include "head.h"
#include "my/string.h"
#include "my/conversion.h"

static void head_parse_long2(head_t *head, char *argument, bool *error)
{
    if (!my_strcmp(argument, "--quiet")
        || !my_strcmp(argument, "--silent")) {
        head->flags |= FLAG_QUIET;
        head->flags &= ~FLAG_VERBOSE;
        return;
    }
    if (!my_strcmp(argument, "--verbose")) {
        head->flags |= FLAG_VERBOSE;
        head->flags &= ~FLAG_QUIET;
        return;
    }
    *error = true;
}

void head_parse_long(head_t *head, char *argument, bool *error)
{
    if (!my_strncmp(argument, "--bytes=", 8)) {
        if (my_str_is_i64(argument + 8)) {
            head->bytes = my_str_to_i64(argument + 8);
            head->flags |= FLAG_BYTES;
            head->flags &= ~FLAG_LINES;
        } else {
            *error = true;
        }
    }
    if (!my_strncmp(argument, "--lines=", 8)) {
        if (my_str_is_i64(argument + 8)) {
            head->lines = my_str_to_i64(argument + 8);
            head->flags |= FLAG_LINES;
            head->flags &= ~FLAG_BYTES;
        } else {
            *error = true;
        }
    }
    head_parse_long2(head, argument, error);
}
