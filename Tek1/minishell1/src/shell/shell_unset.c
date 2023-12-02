/*
** EPITECH PROJECT, 2023
** shell_unset.c
** File description:
** shell_unset.c
*/

#include "my/error.h"
#include "shell.h"
#include "my/string.h"

#include <stdlib.h>

static uint64_t get_variable_index(char **env, char const *name)
{
    uint64_t length = my_strlen(name);
    uint64_t i = 0;

    for (; env[i] != 0; i++) {
        if (!my_strncmp(env[i], name, length) && env[i][length] == '=')
            return i;
    }
    return i;
}

void shell_unset(shell_t *shell, char const *name)
{
    uint64_t index = get_variable_index(shell->env, name);
    uint64_t length = my_strarrlen(shell->env);
    char **copy;

    if (index == length)
        return;
    copy = malloc(length * sizeof(char *));
    if (copy == NULL)
        THROW_VOID(ERROR_ALLOCATION);
    free(shell->env[index]);
    shell->env[index] = 0;
    my_strarrmove(copy, shell->env);
    my_strarrmove(copy + index, shell->env + index + 1);
    my_strarrfree(shell->env);
    shell->env = copy;
}
