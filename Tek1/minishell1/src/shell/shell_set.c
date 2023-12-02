/*
** EPITECH PROJECT, 2023
** shell_set.c
** File description:
** shell_set.c
*/

#include "my/error.h"
#include "shell.h"
#include "my/string.h"

#include <stdlib.h>

static char **get_variable(char **env, char const *name)
{
    uint64_t length = my_strlen(name);

    for (; *env; env++) {
        if (!my_strncmp(*env, name, length) && (*env)[length] == '=')
            return env;
    }
    return NULL;
}

static bool replace(shell_t *shell, char const *name, char *string)
{
    char **variable = get_variable(shell->env, name);

    if (variable == NULL)
        return false;
    free(*variable);
    *variable = string;
    return true;
}

static void append(shell_t *shell, char *string)
{
    uint64_t length = my_strarrlen(shell->env) + 1;
    char **copy = malloc((length + 1) * sizeof(char *));

    if (copy == NULL)
        THROW_VOID(ERROR_ALLOCATION);
    my_strarrmove(copy, shell->env);
    my_strarrfree(shell->env);
    copy[length - 1] = string;
    copy[length] = 0;
    shell->env = copy;
}

void shell_set(shell_t *shell, char const *name, char const *value)
{
    char *string = malloc(my_strlen(name) + my_strlen(value) + 2);

    if (string == NULL)
        THROW_VOID(ERROR_ALLOCATION);
    string[0] = '\0';
    my_strcat(my_strcat(my_strcat(string, name), "="), value);
    if (!replace(shell, name, string))
        append(shell, string);
}
