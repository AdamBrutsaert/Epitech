/*
** EPITECH PROJECT, 2023
** expression_run.c
** File description:
** expression_run.c
*/

#include "expression.h"
#include "my/error.h"

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void expression_run(shell_t *shell, char **arguments)
{
    pid_t pid;
    char *program;
    int status;

    if (expression_execute_builtin(shell, arguments))
        return;
    program = expression_get_program_path(shell, arguments[0]);
    if (ERROR != OK)
        THROW_VOID(ERROR);
    pid = fork();
    if (pid == 0) {
        shell->exit = true;
        expression_execute(shell, program, arguments);
    } else {
        wait(&status);
        expression_process_status(shell, status);
    }
    free(program);
}
