/*
** EPITECH PROJECT, 2023
** command_debug.c
** File description:
** command_debug.c
*/

#include "shell/command.h"
#include "my/stdio.h"

void command_debug(command_t *command)
{
    my_puts("Command:\n");
    for (size_t i = 0; i < command->length; i++)
        pipeline_debug(command->pipelines[i]);
}
