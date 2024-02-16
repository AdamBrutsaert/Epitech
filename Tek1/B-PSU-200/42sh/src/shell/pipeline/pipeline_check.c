/*
** EPITECH PROJECT, 2023
** pipeline_check.c
** File description:
** pipeline_check.c
*/

#include "shell/pipeline_impl.h"

#include <stdio.h>

static bool check_instructions(pipeline_t *pipeline)
{
    instruction_t *instruction;

    for (size_t i = 0; i < VEC_LEN(pipeline->instructions); i++) {
        instruction = VEC_GET(pipeline->instructions, i, instruction_t *);
        if (!instruction_check(instruction))
            return false;
    }
    return true;
}

static bool check_ambiguity(pipeline_t *pipeline)
{
    instruction_t *instruction;

    for (size_t i = 0; i < VEC_LEN(pipeline->instructions); i++) {
        instruction = VEC_GET(pipeline->instructions, i, instruction_t *);
        if (!instruction_check(instruction))
            return false;
        if (i > 0 && instruction_is_redirecting_input(instruction)) {
            fprintf(stderr, "Ambigous input redirect.\n");
            return false;
        }
        if (i + 1 != VEC_LEN(pipeline->instructions)
            && instruction_is_redirecting_output(instruction)) {
            fprintf(stderr, "Ambigous output redirect.\n");
            return false;
        }
    }
    return true;
}

static bool check_null_command(pipeline_t *pipeline)
{
    instruction_t *instruction;

    for (size_t i = 0; i < VEC_LEN(pipeline->instructions); i++) {
        instruction = VEC_GET(pipeline->instructions, i, instruction_t *);
        if (VEC_LEN(pipeline->instructions) > 0
            && instruction_is_empty(instruction)) {
            fprintf(stderr, "Invalid null command.\n");
            return false;
        }
    }
    if (VEC_LEN(pipeline->instructions) == 0
        && (pipeline->separator == SEPARATOR_AND
            || pipeline->separator == SEPARATOR_OR)) {
        fprintf(stderr, "Invalid null command.\n");
        return false;
    }
    return true;
}

bool pipeline_check(pipeline_t *pipeline)
{
    return check_instructions(pipeline)
        && check_ambiguity(pipeline)
        && check_null_command(pipeline);
}
