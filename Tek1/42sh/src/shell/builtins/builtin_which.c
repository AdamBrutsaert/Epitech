/*
** EPITECH PROJECT, 2023
** builtin_which.c
** File description:
** builtin_which.c
*/

#include "shell/builtins.h"
#include "my/memory.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static bool print_if_contains(char *p, char const *name)
{
    bool printed = false;
    char *full_path = calloc(sizeof(char) * (strlen(p) + strlen(name) + 2),
        1);

    if (full_path == NULL)
        return false;
    strcpy(full_path, p);
    strcat(full_path, "/");
    strcat(full_path, name);
    if (access(full_path, R_OK | X_OK) == 0) {
        printf("%s\n", full_path);
        printed = true;
    }
    free(full_path);
    return printed;
}

static bool find_executable_env(shell_t *shell, char const *name)
{
    char *path = shell_get_env_var(shell, "PATH");
    char *tok;

    if (path == NULL)
        return false;
    tok = strtok(path, ":");
    while (tok != NULL) {
        if (print_if_contains(tok, name)) {
            free(path);
            return true;
        }
        tok = strtok(NULL, ":");
    }
    free(path);
    return false;
}

static bool find_executable(shell_t *shell, char const *name)
{
    if (name[0] == '/' || name[0] == '.') {
        if (access(name, R_OK | X_OK) == 0) {
            printf("%s\n", name);
            return true;
        }
        return false;
    }
    return find_executable_env(shell, name);
}

static bool print_alias(shell_t *shell, char *name)
{
    char **alias = alias_find_values(shell_get_aliases(shell), name);

    if (alias == NULL)
        return false;
    printf("%s: \t aliased to ", name);
    for (size_t i = 0; alias[i] != NULL; i++) {
        printf("%s", alias[i]);
        if (alias[i + 1] != NULL)
            printf(" ");
    }
    printf("\n");
    return true;
}

void builtin_which(shell_t *shell, char **arguments)
{
    size_t length = my_array_length(arguments);
    bool err = false;

    if (length == 1) {
        fprintf(stderr, "which: Too few arguments.\n");
        shell_set_status(shell, 1);
        return;
    }
    for (size_t i = 1; i < length; i++) {
        if (print_alias(shell, arguments[i]))
            continue;
        if (!find_executable(shell, arguments[i])) {
            fprintf(stderr, "%s: Command not found.\n", arguments[i]);
            err = true;
            continue;
        }
    }
    shell_set_status(shell, err ? 1 : 0);
}
