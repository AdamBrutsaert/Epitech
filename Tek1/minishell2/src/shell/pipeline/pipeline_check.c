/*
** EPITECH PROJECT, 2023
** pipeline_check.c
** File description:
** pipeline_check.c
*/

#include "shell/pipeline.h"
#include "my/stdio.h"

static bool has_redirect_out(instruction_t *instruction)
{
    for (size_t i = 0; i < instruction->redirects_length; i++) {
        if (instruction->redirects[i].type == REDIRECT_OUTPUT
            || instruction->redirects[i].type == REDIRECT_APPEND)
            return true;
    }
    return false;
}

static bool has_redirect_in(instruction_t *instruction)
{
    for (size_t i = 0; i < instruction->redirects_length; i++) {
        if (instruction->redirects[i].type == REDIRECT_INPUT
            || instruction->redirects[i].type == REDIRECT_HERE_DOCUMENT)
            return true;
    }
    return false;
}

bool pipeline_check(pipeline_t *pipeline)
{
    for (size_t i = 0; i < pipeline->length; i++) {
        if (!instruction_check(pipeline->instructions[i]))
            return false;
        if (i > 0 && has_redirect_in(pipeline->instructions[i])) {
            my_eputs("Ambigous input redirect.\n");
            return false;
        }
        if (i != pipeline->length - 1
            && has_redirect_out(pipeline->instructions[i])) {
            my_eputs("Ambigous output redirect.\n");
            return false;
        }
        if ((i > 0 && pipeline->instructions[i]->arguments_length == 0)
            || (i == 0 && pipeline->length > 1
                && pipeline->instructions[i]->arguments_length == 0)) {
            my_eputs("Invalid null command.\n");
            return false;
        }
    }
    return true;
}
