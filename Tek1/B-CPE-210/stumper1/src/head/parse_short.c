/*
** EPITECH PROJECT, 2023
** parse_short.c
** File description:
** parse_short.c
*/

#include "head.h"
#include "my/conversion.h"
#include "main.h"

#include <stddef.h>

static bool on_short2(head_t *head, char flag, bool *error)
{
    if (flag == 'q') {
        head->flags |= FLAG_QUIET;
        head->flags &= ~FLAG_VERBOSE;
        return false;
    }
    if (flag == 'v') {
        head->flags |= FLAG_VERBOSE;
        head->flags &= ~FLAG_QUIET;
        return false;
    }
    *error = true;
    return false;
}

static bool on_short(head_t *head, char flag, char *value, bool *error)
{
    if (flag == 'c') {
        if (value && my_str_is_i64(value)) {
            head->bytes = my_str_to_i64(value);
            head->flags |= FLAG_BYTES;
            head->flags &= ~FLAG_LINES;
            return true;
        }
        *error = true;
        return false;
    }
    if (flag == 'n') {
        if (value && my_str_is_i64(value)) {
            head->lines = my_str_to_i64(value);
            head->flags |= FLAG_LINES;
            head->flags &= ~FLAG_BYTES;
            return true;
        }
        return false;
    }
    return on_short2(head, flag, error);
}

bool head_parse_short(head_t *head, char *argument, char *value, bool *error)
{
    bool has_used_value = false;

    for (argument++; *argument != '\0'; argument++) {
        if (argument[1] == '\0') {
            has_used_value = has_used_value
                || on_short(head, *argument, value, error);
        } else {
            on_short(head, *argument, NULL, error);
        }
    }
    return has_used_value;
}
