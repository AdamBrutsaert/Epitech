/*
** EPITECH PROJECT, 2023
** command_get_pipelines.c
** File description:
** command_get_pipelines.c
*/

#include "shell/command_impl.h"

vec_t *command_get_pipelines(command_t *command)
{
    return command->pipelines;
}
