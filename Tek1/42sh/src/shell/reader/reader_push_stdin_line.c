/*
** EPITECH PROJECT, 2023
** reader_push_stdin_line.c
** File description:
** reader_push_stdin_line.c
*/

#include "shell/reader_impl.h"

#include <stdio.h>
#include <stdlib.h>

bool reader_push_stdin_line(reader_t *reader)
{
    char *line = NULL;
    size_t length = 0;

    if (getline(&line, &length, stdin) == -1 || !reader_push(reader, line)) {
        free(line);
        return false;
    }
    free(line);
    return true;
}
