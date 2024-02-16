/*
** EPITECH PROJECT, 2023
** builtins.h
** File description:
** builtins.h
*/

#pragma once

#include "shell.h"

bool is_builtin(const char *program);

void builtin_execute(shell_t *shell, char **arguments);
void builtin_env(shell_t *shell, char **arguments);
void builtin_setenv(shell_t *shell, char **arguments);
void builtin_unsetenv(shell_t *shell, char **arguments);
void builtin_cd(shell_t *shell, char **arguments);
void builtin_exit(shell_t *shell, char **arguments);
void builtin_alias(shell_t *shell, char **arguments);
void builtin_unalias(shell_t *shell, char **arguments);
void builtin_history(shell_t *shell);
void builtin_where(shell_t *shell, char **arguments);
void builtin_which(shell_t *shell, char **arguments);
