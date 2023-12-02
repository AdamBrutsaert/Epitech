/*
** EPITECH PROJECT, 2023
** builtins.h
** File description:
** builtins.h
*/

#pragma once

#include "interpreter.h"

bool is_builtin(const char *program);

void builtin_execute(interpreter_t *interpreter, char **arguments);
void builtin_env(interpreter_t *interpreter, char **arguments);
void builtin_setenv(interpreter_t *interpreter, char **arguments);
void builtin_unsetenv(interpreter_t *interpreter, char **arguments);
void builtin_cd(interpreter_t *interpreter, char **arguments);
void builtin_exit(interpreter_t *interpreter, char **arguments);
