/*
** EPITECH PROJECT, 2023
** command_add_pipeline.c
** File description:
** command_add_pipeline.c
*/

#include "shell/command.h"
#include "my/memory.h"

#include <stdlib.h>

static bool grow(command_t *command)
{
    size_t capacity = command->capacity * 2 + !command->capacity;
    pipeline_t **pipelines = malloc(sizeof(pipeline_t *) * capacity);

    if (pipelines == NULL)
        return false;
    my_memmove(
        pipelines,
        command->pipelines,
        sizeof(pipeline_t *) * command->length
    );
    free(command->pipelines);
    command->pipelines = pipelines;
    command->capacity = capacity;
    return true;
}

bool command_add_pipeline(command_t *command, pipeline_t *pipeline)
{
    if (command->length == command->capacity && !grow(command))
        return false;
    command->pipelines[command->length] = pipeline;
    command->length++;
    return true;
}
