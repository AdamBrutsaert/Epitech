/*
** EPITECH PROJECT, 2023
** expression_execute.c
** File description:
** expression_execute.c
*/

#include "expression.h"
#include "my/stdio.h"

#include <unistd.h>
#include <errno.h>

void expression_execute(shell_t *shell, char *program, char **arguments)
{
    if (execve(program, arguments, shell->env) == -1) {
        if (errno == ENOEXEC) {
            my_eputs(program);
            my_eputs(": Exec format error. Wrong Architecture.\n");
            shell->status = 1;
        }
        errno = 0;
    }
}
