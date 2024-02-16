/*
** EPITECH PROJECT, 2023
** command_print.c
** File description:
** command_print.c
*/

#include "shell/command_impl.h"

#include <stdio.h>

void command_print(command_t *command)
{
    printf("Command:\n");
    for (size_t i = 0; i < VEC_LEN(command->pipelines); i++)
        pipeline_print(VEC_GET(command->pipelines, i, pipeline_t *));
}
