/*
** EPITECH PROJECT, 2023
** builtin_where.c
** File description:
** builtin_where.c
*/

#include "shell/builtins.h"
#include "my/memory.h"
#include "shell/alias.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static void print_if_contains(char *p, char const *name)
{
    char *full_path = calloc(sizeof(char) * (strlen(p) + strlen(name) + 2),
        1);

    if (full_path == NULL)
        return;
    strcpy(full_path, p);
    strcat(full_path, "/");
    strcat(full_path, name);
    if (access(full_path, R_OK | X_OK) == 0)
        printf("%s\n", full_path);
    free(full_path);
}

static bool shell_where_env(shell_t *shell, char const *name)
{
    char *path = shell_get_env_var(shell, "PATH");
    char *tok;

    if (path == NULL)
        return false;
    tok = strtok(path, ":");
    while (tok != NULL) {
        print_if_contains(tok, name);
        tok = strtok(NULL, ":");
    }
    free(path);
    return true;
}

static bool print_alias(shell_t *shell, char *name)
{
    char **alias = alias_find_values(shell_get_aliases(shell), name);

    if (alias == NULL)
        return false;
    printf("%s is aliased to ", name);
    for (size_t i = 0; alias[i] != NULL; i++) {
        printf("%s", alias[i]);
        if (alias[i + 1] != NULL)
            printf(" ");
    }
    printf("\n");
    return true;
}

static bool shell_where(shell_t *shell, char *name)
{
    bool contains = false;
    bool printed = false;

    for (size_t i = 0; name[i] != '\0'; i++) {
        if (name[i] == '/')
            contains = true;
    }
    if (contains) {
        fprintf(stderr, "where: / in command makes no sense\n");
        return false;
    }
    if (print_alias(shell, name))
        printed = true;
    return shell_where_env(shell, name) || printed;
}

void builtin_where(shell_t *shell, char **arguments)
{
    size_t length = my_array_length(arguments);
    bool err = false;

    if (length == 1) {
        fprintf(stderr, "where: Too few arguments.\n");
        shell_set_status(shell, 1);
        return;
    }
    for (size_t i = 1; i < length; i++) {
        if (!shell_where(shell, arguments[i]))
            err = true;
    }
    shell_set_status(shell, err ? 1 : 0);
}
