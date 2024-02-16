/*
** EPITECH PROJECT, 2023
** pipeline.h
** File description:
** pipeline.h
*/

#pragma once

#include "instruction.h"

typedef enum {
    SEPARATOR_NONE = 0,
    SEPARATOR_SEMICOLON,
    SEPARATOR_NEWLINE,
} separator_t;

typedef struct {
    size_t capacity;
    size_t length;
    instruction_t **instructions;
    separator_t separator;
} pipeline_t;

pipeline_t *pipeline_create(void);
void pipeline_destroy(pipeline_t *pipeline);

bool pipeline_is_empty(pipeline_t *pipeline);
bool pipeline_check(pipeline_t *pipeline);
void pipeline_debug(pipeline_t *pipeline);
bool pipeline_add_instruction(pipeline_t *pipeline, instruction_t *instruction);
void pipeline_set_separator(pipeline_t *pipeline, separator_t separator);
