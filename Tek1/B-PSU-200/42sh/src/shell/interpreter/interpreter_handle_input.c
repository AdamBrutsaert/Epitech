/*
** EPITECH PROJECT, 2023
** interpreter_handle_input.c
** File description:
** interpreter_handle_input.c
*/

#include "shell/interpreter_impl.h"

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

static void on_error(redirection_t *redirection)
{
    char *value = redirection_get_value(redirection);

    if (errno == EACCES)
        fprintf(stderr, "%s: Permission denied.\n", value);
    if (errno == EISDIR)
        fprintf(stderr, "%s: Is a directory.\n", value);
    if (errno == EMFILE)
        fprintf(stderr, "%s: Too many open files.\n", value);
    errno = 0;
}

bool interpreter_handle_input(
    interpreter_t *interpreter,
    redirection_t *redirection
)
{
    int fd;

    interpreter->stdin_copy = dup(STDIN_FILENO);
    if (interpreter->stdin_copy == -1) {
        on_error(redirection);
        return false;
    }
    fd = open(redirection_get_value(redirection), O_RDONLY);
    if (fd == -1) {
        on_error(redirection);
        return false;
    }
    if (dup2(fd, STDIN_FILENO) == -1) {
        on_error(redirection);
        close(fd);
        return false;
    }
    close(fd);
    return true;
}
