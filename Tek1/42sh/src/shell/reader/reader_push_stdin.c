/*
** EPITECH PROJECT, 2023
** reader_push_stdin.c
** File description:
** reader_push_stdin.c
*/

#include "shell/reader_impl.h"
#include "my/stdio.h"

#include <stdlib.h>
#include <unistd.h>

bool reader_push_stdin(reader_t *reader)
{
    char *buffer = my_read_fd(STDIN_FILENO);

    if (buffer == NULL || !reader_push(reader, buffer))
        return false;
    free(buffer);
    return true;
}
