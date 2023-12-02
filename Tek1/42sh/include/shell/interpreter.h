/*
** EPITECH PROJECT, 2023
** interpreter.h
** File description:
** interpreter.h
*/

#pragma once

#include "command.h"

typedef struct interpreter interpreter_t;
struct shell;

interpreter_t *interpreter_new(void);
void interpreter_delete(interpreter_t *interpreter);

void interpreter_process(
    interpreter_t *interpreter,
    struct shell *shell,
    command_t *command
);
