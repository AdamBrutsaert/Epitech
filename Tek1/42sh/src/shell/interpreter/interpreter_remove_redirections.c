/*
** EPITECH PROJECT, 2023
** interpreter_remove_redirections.c
** File description:
** interpreter_remove_redirections.c
*/

#include "shell/interpreter_impl.h"

#include <unistd.h>

void interpreter_remove_redirections(interpreter_t *interpreter)
{
    if (interpreter->stdin_copy != -1) {
        dup2(interpreter->stdin_copy, STDIN_FILENO);
        close(interpreter->stdin_copy);
        interpreter->stdin_copy = -1;
    }
    if (interpreter->stdout_copy != -1) {
        dup2(interpreter->stdout_copy, STDOUT_FILENO);
        close(interpreter->stdout_copy);
        interpreter->stdout_copy = -1;
    }
}
