/*
** EPITECH PROJECT, 2023
** builtins.h
** File description:
** builtins.h
*/

#pragma once

#include "shell.h"

void builtin_cd(shell_t *shell, char **arguments);
void builtin_unsetenv(shell_t *shell, char **arguments);
void builtin_setenv(shell_t *shell, char **arguments);
void builtin_env(shell_t *shell, char **arguments);
void builtin_exit(shell_t *shell, char **arguments);
