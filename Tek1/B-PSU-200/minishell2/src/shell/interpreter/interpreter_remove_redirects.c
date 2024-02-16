/*
** EPITECH PROJECT, 2023
** interpreter_remove_redirections.c
** File description:
** interpreter_remove_redirections.c
*/

#include "shell/interpreter.h"

#include <unistd.h>

void interpreter_remove_redirects(instruction_t *instruction)
{
    if (instruction->stdin_copy != -1) {
        dup2(instruction->stdin_copy, STDIN_FILENO);
        close(instruction->stdin_copy);
    }
    if (instruction->stdout_copy != -1) {
        dup2(instruction->stdout_copy, STDOUT_FILENO);
        close(instruction->stdout_copy);
    }
}
