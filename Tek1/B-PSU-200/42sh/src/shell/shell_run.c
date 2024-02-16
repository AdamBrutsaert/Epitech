/*
** EPITECH PROJECT, 2023
** shell_run.c
** File description:
** shell_run.c
*/

#include "shell_impl.h"
#include "my/stdio.h"
#include "shell/history.h"

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

static void parse_and_execute(shell_t *shell)
{
    command_t *command;

    while (lexer_peek_type(shell->lexer, 0) != TOKEN_END
        && !shell->exit) {
        command = parse(shell->lexer);
        if (command != NULL) {
            interpreter_process(shell->interpreter, shell, command);
            command_delete(command);
        } else {
            shell->status = 1;
        }
    }
}

static void repl(shell_t *shell)
{
    while (!shell->exit) {
        reader_clear(shell->reader);
        lexer_clear(shell->lexer);
        if (isatty(STDIN_FILENO))
            shell_prompt(shell);
        if (!reader_push_stdin_line(shell->reader))
            return;
        shell_add_to_history(shell);
        if (!lexer_process(shell->lexer, shell->reader)) {
            shell->status = 1;
            continue;
        }
        parse_and_execute(shell);
    }
}

int shell_run(shell_t *shell)
{
    repl(shell);
    return shell->status;
}
