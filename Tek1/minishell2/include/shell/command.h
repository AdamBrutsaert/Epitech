/*
** EPITECH PROJECT, 2023
** command.h
** File description:
** command.h
*/

#pragma once

#include "pipeline.h"

typedef struct {
    size_t capacity;
    size_t length;
    pipeline_t **pipelines;
} command_t;

command_t *command_create(void);
void command_destroy(command_t *command);

bool command_is_empty(command_t *command);
bool command_check(command_t *command);
void command_debug(command_t *command);
bool command_add_pipeline(command_t *command, pipeline_t *pipeline);
