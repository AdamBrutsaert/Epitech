/*
** EPITECH PROJECT, 2023
** shell_delete.c
** File description:
** shell_delete.c
*/

#include "shell_impl.h"
#include "my/memory.h"
#include "shell/history.h"

#include <stdlib.h>

void shell_delete(shell_t *shell)
{

    if (shell == NULL)
        return;
    reader_delete(shell->reader);
    lexer_delete(shell->lexer);
    interpreter_delete(shell->interpreter);
    alias_delete_all(shell->aliases);
    my_array_free(shell->env);
    for (size_t i = 0; i < VEC_LEN(shell->history); i++)
        free(VEC_GET(shell->history, i, history_t).cmd);
    vec_delete(shell->history);
    free(shell);
}
