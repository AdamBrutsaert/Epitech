/*
** EPITECH PROJECT, 2023
** instruction.h
** File description:
** instruction.h
*/

#pragma once

#include "redirect.h"

#include <stddef.h>
#include <stdbool.h>
#include <sys/types.h>

typedef struct {
    size_t arguments_capacity;
    size_t arguments_length;
    char **arguments;

    size_t redirects_capacity;
    size_t redirects_length;
    redirect_t *redirects;

    int pipefd[2];
    pid_t pid;
    int stdout_copy;
    int stdin_copy;
} instruction_t;

instruction_t *instruction_create(void);
void instruction_destroy(instruction_t *instruction);

bool instruction_is_empty(instruction_t *instruction);
bool instruction_check(instruction_t *instruction);
void instruction_debug(instruction_t *instruction);
bool instruction_add_argument(instruction_t *instruction, char *argument);
bool instruction_add_redirect(
    instruction_t *instruction,
    redirect_type_t type,
    char *value
);
