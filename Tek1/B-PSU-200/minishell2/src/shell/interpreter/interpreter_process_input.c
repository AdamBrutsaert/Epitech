/*
** EPITECH PROJECT, 2023
** interpreter_process_input.c
** File description:
** interpreter_process_input.c
*/

#include "shell/interpreter.h"
#include "my/stdio.h"

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

static void on_open_error(redirect_t *redirect)
{
    if (errno == EACCES) {
        my_eputs(redirect->value);
        my_eputs(": Permission denied.\n");
    }
    if (errno == EISDIR) {
        my_eputs(redirect->value);
        my_eputs(": Is a directory.\n");
    }
    errno = 0;
}

bool interpreter_process_input(
    instruction_t *instruction,
    redirect_t *redirect
)
{
    int fd;

    instruction->stdin_copy = dup(STDIN_FILENO);
    if (instruction->stdin_copy == -1)
        return false;
    fd = open(redirect->value, O_RDONLY);
    if (fd == -1) {
        on_open_error(redirect);
        return false;
    }
    if (dup2(fd, STDIN_FILENO) == -1) {
        close(fd);
        return false;
    }
    close(fd);
    return true;
}
