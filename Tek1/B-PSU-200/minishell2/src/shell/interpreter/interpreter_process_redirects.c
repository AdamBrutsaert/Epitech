/*
** EPITECH PROJECT, 2023
** interpreter_process_redirections.c
** File description:
** interpreter_process_redirections.c
*/

#include "shell/interpreter.h"

static bool process_redirect(instruction_t *instruction, redirect_t *redirect)
{
    if (redirect->type == REDIRECT_OUTPUT)
        return interpreter_process_output(instruction, redirect);
    if (redirect->type == REDIRECT_APPEND)
        return interpreter_process_append(instruction, redirect);
    if (redirect->type == REDIRECT_INPUT)
        return interpreter_process_input(instruction, redirect);
    if (redirect->type == REDIRECT_HERE_DOCUMENT)
        return interpreter_process_here_document(instruction, redirect);
    return false;
}

bool interpreter_process_redirects(instruction_t *instruction)
{
    for (size_t i = 0; i < instruction->redirects_length; i++) {
        if (!process_redirect(instruction, &instruction->redirects[i]))
            return false;
    }
    return true;
}
