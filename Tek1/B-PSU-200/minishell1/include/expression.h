/*
** EPITECH PROJECT, 2023
** expression.h
** File description:
** expression.h
*/

#pragma once

#include "shell.h"

#include <stdbool.h>

char **expression_parse(char const *string);
char **expression_split(char const *string);
void expression_sanatize(char **arguments);

bool expression_execute_builtin(shell_t *shell, char **arguments);
char *expression_get_program_path(shell_t *shell, char *name);
void expression_execute(shell_t *shell, char *program, char **arguments);
void expression_process_status(shell_t *shell, int status);
void expression_run(shell_t *shell, char **arguments);
