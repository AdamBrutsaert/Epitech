/*
** EPITECH PROJECT, 2023
** command.h
** File description:
** command.h
*/

#pragma once

#include "pipeline.h"

typedef struct command command_t;

command_t *command_new(void);
void command_delete(command_t *command);

bool command_push_pipeline(command_t *command, pipeline_t *pipeline);

vec_t *command_get_pipelines(command_t *command);

bool command_is_empty(command_t *command);
bool command_check(command_t *command);

// Debug
void command_print(command_t *command);
