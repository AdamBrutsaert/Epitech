/*
** EPITECH PROJECT, 2023
** shell.h
** File description:
** shell.h
*/

#pragma once

#include "shell/parser.h"
#include "shell/alias.h"
#include <stdbool.h>
#include "my/vector.h"

typedef struct shell shell_t;

shell_t *shell_new(int argc, char **argv, char **envp);
void shell_delete(shell_t *shell);

int shell_run(shell_t *shell);

bool shell_set_env_var(shell_t *shell, const char *key, const char *value);
void shell_unset_env_var(shell_t *shell, const char *key);
char *shell_get_env_var(shell_t *shell, const char *key);
char **shell_get_env(shell_t *shell);
char *shell_find_program(shell_t *shell, const char *program);

void shell_exit(shell_t *shell);
void shell_set_status(shell_t *shell, int status);
int shell_get_status(shell_t *shell);

alias_t *shell_get_aliases(shell_t *shell);
void shell_preprend_alias(shell_t *shell, alias_t *alias);
void shell_set_alias(shell_t *shell, char **arguments);
void shell_remove_alias(shell_t *shell, const char *name);
void shell_process_alias(shell_t *shell, instruction_t *instruction);

vec_t *shell_get_history(shell_t *shell);
