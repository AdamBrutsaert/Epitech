/*
** EPITECH PROJECT, 2023
** shell.h
** File description:
** shell.h
*/

#pragma once

#include <stdbool.h>

typedef struct {
    char **env;
    bool exit;
    int status;
} shell_t;

shell_t *shell_create(char **env);
void shell_destroy(shell_t *shell);

int shell_run(shell_t *shell);

void shell_unset(shell_t *shell, char const *name);
void shell_set(shell_t *shell, char const *name, char const *value);
char *shell_get(shell_t *shell, char const *name);
char **shell_get_path_directories(shell_t *shell);
char *shell_find_binary(shell_t *shell, char const *name);
