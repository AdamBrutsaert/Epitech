/*
** EPITECH PROJECT, 2023
** command_check.c
** File description:
** command_check.c
*/

#include "shell/command_impl.h"

#include <stdio.h>

static bool check_pipelines(command_t *command)
{
    for (size_t i = 0; i < VEC_LEN(command->pipelines); i++) {
        if (!pipeline_check(VEC_GET(command->pipelines, i, pipeline_t *)))
            return false;
    }
    return true;
}

static bool check_null_command(command_t *command)
{
    pipeline_t *pipeline;

    if (VEC_LEN(command->pipelines) == 0)
        return true;
    pipeline = VEC_GET(command->pipelines, 0, pipeline_t *);
    if (pipeline_get_separator(pipeline) == SEPARATOR_AND
        || pipeline_get_separator(pipeline) == SEPARATOR_OR) {
        fprintf(stderr, "Invalid null command.\n");
        return false;
    }
    return true;
}

bool command_check(command_t *command)
{
    return check_pipelines(command)
        && check_null_command(command);
}
