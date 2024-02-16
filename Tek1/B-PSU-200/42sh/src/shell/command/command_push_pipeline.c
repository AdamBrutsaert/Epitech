/*
** EPITECH PROJECT, 2023
** command_push_pipeline.c
** File description:
** command_push_pipeline.c
*/

#include "shell/command_impl.h"

bool command_push_pipeline(command_t *command, pipeline_t *pipeline)
{
    return VEC_PUSH(command->pipelines, pipeline);
}
