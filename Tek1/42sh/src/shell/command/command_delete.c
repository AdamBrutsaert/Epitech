/*
** EPITECH PROJECT, 2023
** command_delete.c
** File description:
** command_delete.c
*/

#include "shell/command_impl.h"

#include <stdlib.h>

void command_delete(command_t *command)
{
    if (command == NULL)
        return;
    vec_clear_and_delete(command->pipelines, (deleter_t)pipeline_delete);
    vec_delete(command->pipelines);
    free(command);
}
