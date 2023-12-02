/*
** EPITECH PROJECT, 2023
** instruction_check.c
** File description:
** instruction_check.c
*/

#include "shell/instruction.h"
#include "my/stdio.h"

static bool check(
    redirect_t *redirect,
    bool *redirect_in,
    bool *redirect_out
)
{
    if ((redirect->type == REDIRECT_INPUT && *redirect_in)
        || (redirect->type == REDIRECT_HERE_DOCUMENT && *redirect_in)) {
        my_eputs("Ambiguous input redirect.\n");
        return false;
    }
    if ((redirect->type == REDIRECT_OUTPUT && *redirect_out)
        || (redirect->type == REDIRECT_APPEND && *redirect_out)) {
        my_eputs("Ambiguous output redirect.\n");
        return false;
    }
    if (redirect->type == REDIRECT_INPUT
        || redirect->type == REDIRECT_HERE_DOCUMENT)
        *redirect_in = true;
    if (redirect->type == REDIRECT_OUTPUT
        || redirect->type == REDIRECT_APPEND)
        *redirect_out = true;
    return true;
}

bool instruction_check(instruction_t *instruction)
{
    bool redirect_in = false;
    bool redirect_out = false;

    for (size_t i = 0; i < instruction->redirects_length; i++) {
        if (!check(&instruction->redirects[i], &redirect_in, &redirect_out))
            return false;
    }
    return true;
}
