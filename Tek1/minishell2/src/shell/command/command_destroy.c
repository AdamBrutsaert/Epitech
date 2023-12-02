/*
** EPITECH PROJECT, 2023
** command_destroy.c
** File description:
** command_destroy.c
*/

#include "shell/command.h"

#include <stdlib.h>

void command_destroy(command_t *command)
{
    if (command == NULL)
        return;
    for (size_t i = 0; i < command->length; i++)
        pipeline_destroy(command->pipelines[i]);
    free(command->pipelines);
    free(command);
}
