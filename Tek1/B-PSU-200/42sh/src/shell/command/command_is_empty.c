/*
** EPITECH PROJECT, 2023
** command_is_empty.c
** File description:
** command_is_empty.c
*/

#include "shell/command_impl.h"

bool command_is_empty(command_t *command)
{
    pipeline_t *pipeline;

    for (size_t i = 0; i < VEC_LEN(command->pipelines); i++) {
        pipeline = VEC_GET(command->pipelines, i, pipeline_t *);
        if (!pipeline_is_empty(pipeline))
            return false;
    }
    return true;
}
