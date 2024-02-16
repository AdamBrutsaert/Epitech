/*
** EPITECH PROJECT, 2023
** interpreter_process_pipeline.c
** File description:
** interpreter_process_pipeline.c
*/

#include "shell/interpreter_impl.h"
#include "shell.h"

static bool should_process(interpreter_t *interpreter)
{
    int status = shell_get_status(interpreter->shell);

    if (pipeline_is_empty(interpreter->pipeline))
        return false;
    if (status != 0
        && pipeline_get_separator(interpreter->pipeline) == SEPARATOR_AND)
        return false;
    if (status == 0
        && pipeline_get_separator(interpreter->pipeline) == SEPARATOR_OR)
        return false;
    return true;
}

void interpreter_process_pipeline(interpreter_t *interpreter)
{
    vec_t *instructions = pipeline_get_instructions(interpreter->pipeline);

    if (!should_process(interpreter))
        return;
    for (size_t i = 0; i < VEC_LEN(instructions); i++) {
        interpreter->instruction = VEC_GET(instructions, i, instruction_t *);
        interpreter->instruction_index = i;
        interpreter_process_instruction(interpreter);
    }
    interpreter_wait_processes(interpreter);
}
