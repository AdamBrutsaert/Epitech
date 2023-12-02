/*
** EPITECH PROJECT, 2023
** pipeline.h
** File description:
** pipeline.h
*/

#pragma once

#include "instruction.h"

typedef struct pipeline pipeline_t;

typedef enum {
    SEPARATOR_NONE = 0,
    SEPARATOR_SEMICOLON,
    SEPARATOR_AND,
    SEPARATOR_OR,
} separator_t;

pipeline_t *pipeline_new(void);
void pipeline_delete(pipeline_t *pipeline);

bool pipeline_push_instruction(
    pipeline_t *pipeline,
    instruction_t *instruction
);
void pipeline_set_separator(pipeline_t *pipeline, separator_t separator);

vec_t *pipeline_get_instructions(pipeline_t *pipeline);
separator_t pipeline_get_separator(pipeline_t *pipeline);

bool pipeline_is_empty(pipeline_t *pipeline);
bool pipeline_check(pipeline_t *pipeline);

// Debug
void pipeline_print(pipeline_t *pipeline);
