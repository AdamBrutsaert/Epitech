/*
** EPITECH PROJECT, 2023
** interpreter_handle_here_document.c
** File description:
** interpreter_handle_here_document.c
*/

#include "shell/interpreter_impl.h"

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static bool is_end(char *line, char *value)
{
    size_t i = 0;

    while (line[i] != '\n' && line[i] != '\0' && line[i] == value[i])
        i++;
    if (line[i] == '\n' && value[i] == '\0')
        return true;
    return line[i] - value[i] == 0;
}

static bool write_in(int pipefd[2], redirection_t *redirection)
{
    char *line = NULL;
    size_t len = 0;

    do {
        if (line != NULL)
            write(pipefd[1], line, strlen(line));
        if (getline(&line, &len, stdin) == -1)
            break;
    } while (!is_end(line, redirection_get_value(redirection)));
    close(pipefd[1]);
    free(line);
    return true;
}

static bool redirect_in(interpreter_t *interpreter, int pipefd[2])
{
    interpreter->stdin_copy = dup(STDIN_FILENO);
    if (interpreter->stdin_copy == -1) {
        close(pipefd[0]);
        return false;
    }
    if (dup2(pipefd[0], STDIN_FILENO) == -1) {
        close(pipefd[0]);
        return false;
    }
    close(pipefd[0]);
    return true;
}

bool interpreter_handle_here_document(
    interpreter_t *interpreter,
    redirection_t *redirection
)
{
    int pipefd[2];

    if (pipe(pipefd) == -1)
        return false;
    if (!write_in(pipefd, redirection))
        return false;
    if (!redirect_in(interpreter, pipefd))
        return false;
    return true;
}
