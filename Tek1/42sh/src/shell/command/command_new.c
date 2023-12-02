/*
** EPITECH PROJECT, 2023
** command_new.c
** File description:
** command_new.c
*/

#include "shell/command_impl.h"

#include <stdlib.h>

command_t *command_new(void)
{
    command_t *command = calloc(1, sizeof(command_t));

    command->pipelines = vec_new(sizeof(pipeline_t *));
    if (command->pipelines == NULL) {
        command_delete(command);
        return NULL;
    }
    return command;
}
