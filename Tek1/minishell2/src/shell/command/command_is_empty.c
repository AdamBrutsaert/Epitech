/*
** EPITECH PROJECT, 2023
** command_is_empty.c
** File description:
** command_is_empty.c
*/

#include "shell/command.h"

bool command_is_empty(command_t *command)
{
    for (size_t i = 0; i < command->length; i++) {
        if (!pipeline_is_empty(command->pipelines[i]))
            return false;
    }
    return true;
}
