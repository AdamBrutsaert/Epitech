/*
** EPITECH PROJECT, 2023
** interpreter_handle_output.c
** File description:
** interpreter_handle_output.c
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

bool interpreter_handle_output(
    interpreter_t *interpreter,
    redirection_t *redirection
)
{
    int fd;

    interpreter->stdout_copy = dup(STDOUT_FILENO);
    if (interpreter->stdout_copy == -1) {
        on_error(redirection);
        return false;
    }
    fd = open(redirection_get_value(redirection),
        O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        on_error(redirection);
        return false;
    }
    if (dup2(fd, STDOUT_FILENO) == -1) {
        on_error(redirection);
        close(fd);
        return false;
    }
    close(fd);
    return true;
}
