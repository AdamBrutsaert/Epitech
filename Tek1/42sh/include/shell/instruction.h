/*
** EPITECH PROJECT, 2023
** instruction.h
** File description:
** instruction.h
*/

#pragma once

#include "redirection.h"
#include "my/vector.h"

#include <stdbool.h>

typedef struct instruction instruction_t;

instruction_t *instruction_new(void);
void instruction_delete(instruction_t *instruction);

bool instruction_push_redirection(
    instruction_t *instruction,
    redirection_t *redirection
);
bool instruction_push_argument(
    instruction_t *instruction,
    const char *argument
);

vec_t *instruction_get_redirections(instruction_t *instruction);
char **instruction_get_arguments(instruction_t *instruction);

bool instruction_check(instruction_t *instruction);
bool instruction_is_empty(instruction_t *instruction);
bool instruction_is_redirecting_input(instruction_t *instruction);
bool instruction_is_redirecting_output(instruction_t *instruction);

// Debug
void instruction_print(instruction_t *instruction);
