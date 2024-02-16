/*
** EPITECH PROJECT, 2023
** shell_run.c
** File description:
** shell_run.c
*/

#include "shell.h"
#include "expression.h"
#include "my/stdio.h"
#include "my/string.h"
#include "my/error.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static char *read_stdin(void)
{
    char *line = NULL;
    size_t length;

    if (getline(&line, &length, stdin) == -1) {
        if (isatty(STDIN_FILENO))
            my_puts("exit\n");
        return NULL;
    }
    return line;
}

int shell_run(shell_t *shell)
{
    char *expression = NULL;
    char **arguments;

    while (!shell->exit) {
        if (isatty(STDIN_FILENO))
            my_puts("$> ");
        expression = read_stdin();
        if (expression == NULL)
            break;
        arguments = expression_parse(expression);
        free(expression);
        if (ERROR != OK)
            THROW_ZERO(ERROR);
        expression_run(shell, arguments);
        my_strarrfree(arguments);
        if (ERROR != OK)
            THROW_ZERO(ERROR);
    }
    return shell->status;
}
