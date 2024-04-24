/*
** EPITECH PROJECT, 2024
** command_create.c
** File description:
** command_create.c
*/

#include "parsing/parser.h"

#include "my/memory/allocation.h"

command_t *command_create(void)
{
    command_t *command = allocate(sizeof(command_t));

    command->name = string_create();
    command->arguments = vec_create(sizeof(string_t *));
    return command;
}
