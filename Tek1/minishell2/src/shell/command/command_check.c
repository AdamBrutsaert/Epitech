/*
** EPITECH PROJECT, 2023
** command_check.c
** File description:
** command_check.c
*/

#include "shell/command.h"

bool command_check(command_t *command)
{
    for (size_t i = 0; i < command->length; i++) {
        if (!pipeline_check(command->pipelines[i]))
            return false;
    }
    return true;
}
