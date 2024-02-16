/*
** EPITECH PROJECT, 2023
** command_create.c
** File description:
** command_create.c
*/

#include "shell/command.h"
#include "my/memory.h"

#include <stdlib.h>

command_t *command_create(void)
{
    command_t *command = malloc(sizeof(command_t));

    if (command == NULL)
        return NULL;
    my_memset(command, 0, sizeof(command_t));
    return command;
}
