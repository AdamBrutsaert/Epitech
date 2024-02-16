/*
** EPITECH PROJECT, 2023
** interpreter_process_here_document.c
** File description:
** interpreter_process_here_document.c
*/

#include "shell/interpreter.h"
#include "my/string.h"

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

static bool write_in(int pipefd[2], redirect_t *redirect)
{
    char *line = NULL;
    size_t len = 0;

    do {
        if (line != NULL)
            write(pipefd[1], line, my_strlen(line));
        if (getline(&line, &len, stdin) == -1) {
            close(pipefd[0]);
            close(pipefd[1]);
            free(line);
            return false;
        }
    } while (!is_end(line, redirect->value));
    close(pipefd[1]);
    free(line);
    return true;
}

static bool redirect_in(instruction_t *instruction, int pipefd[2])
{
    instruction->stdin_copy = dup(STDIN_FILENO);
    if (instruction->stdin_copy == -1) {
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

bool interpreter_process_here_document(
    instruction_t *instruction,
    redirect_t *redirect
)
{
    int pipefd[2];

    if (pipe(pipefd) == -1)
        return false;
    if (!write_in(pipefd, redirect))
        return false;
    if (!redirect_in(instruction, pipefd))
        return false;
    return true;
}
