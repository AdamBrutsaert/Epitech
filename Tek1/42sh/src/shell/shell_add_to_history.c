/*
** EPITECH PROJECT, 2023
** shell_add_to_history.c
** File description:
** shell_add_to_history.c
*/

#include "shell_impl.h"
#include "shell/history.h"

#include <string.h>
#include <stdlib.h>

static char *remove_trailing_newline(char *str)
{
    size_t length = strlen(str);

    if (length > 0 && str[length - 1] == '\n')
        str[length - 1] = '\0';
    return str;
}

static bool is_empty_line(char *line)
{
    for (size_t i = 0; line[i] != '\0'; i++) {
        if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
            return false;
    }
    return true;
}

void shell_add_to_history(shell_t *shell)
{
    history_t history;
    char *line = reader_get_buffer(shell->reader);

    if (line == NULL || strlen(line) == 0 || is_empty_line(line)) {
        free(line);
        return;
    }
    history.cmd = remove_trailing_newline(line);
    history.time = time(0);
    if (!VEC_PUSH(shell->history, history))
        free(line);
}
