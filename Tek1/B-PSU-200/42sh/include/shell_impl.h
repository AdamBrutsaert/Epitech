/*
** EPITECH PROJECT, 2023
** shell_impl.h
** File description:
** shell_impl.h
*/

#pragma once

#include "shell.h"
#include "shell/parser.h"
#include "shell/interpreter.h"
#include "shell/alias.h"

#include <stddef.h>

struct shell {
    reader_t *reader;
    lexer_t *lexer;
    interpreter_t *interpreter;
    alias_t *aliases;

    vec_t *history;

    char **env;
    int status;
    bool exit;
};

bool shell_copy_env(shell_t *shell, char **envp);
size_t shell_find_env_var(shell_t *shell, const char *key);
char **shell_get_path_directories(shell_t *shell);
void shell_prompt(shell_t *shell);
void shell_add_to_history(shell_t *shell);
