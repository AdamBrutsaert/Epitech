/*
** EPITECH PROJECT, 2023
** shell_new.c
** File description:
** shell_new.c
*/

#include "shell_impl.h"
#include "shell/history.h"

#include <stdlib.h>

shell_t *shell_new(
    __attribute__((unused)) int argc,
    __attribute__((unused)) char **argv,
    char **envp)
{
    shell_t *shell = calloc(1, sizeof(shell_t));

    if (shell == NULL)
        return NULL;
    shell->reader = reader_new();
    shell->lexer = lexer_new();
    shell->interpreter = interpreter_new();
    shell->history = vec_new(sizeof(history_t));
    if (!shell->history || !shell->reader
        || !shell->lexer || !shell->interpreter
        || !shell_copy_env(shell, envp)) {
        shell_delete(shell);
        return NULL;
    }
    return shell;
}
