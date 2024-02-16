/*
** EPITECH PROJECT, 2023
** interpreter_process.c
** File description:
** interpreter_process.c
*/

#include "shell/interpreter_impl.h"
#include "shell.h"

void interpreter_process(
    interpreter_t *interpreter,
    struct shell *shell,
    command_t *command
)
{
    vec_t *pipelines = command_get_pipelines(command);

    interpreter->shell = shell;
    for (size_t i = 0; i < VEC_LEN(pipelines); i++) {
        vec_clear(interpreter->processes);
        vec_clear(interpreter->pipes);
        interpreter->pipeline = VEC_GET(pipelines, i, pipeline_t *);
        interpreter_process_pipeline(interpreter);
    }
}
