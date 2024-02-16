/*
** EPITECH PROJECT, 2023
** shell_set_env_var.c
** File description:
** shell_set_env_var.c
*/

#include "shell_impl.h"

#include <stdlib.h>
#include <string.h>

static char *create_string(const char *key, const char *value)
{
    char *string = malloc(strlen(key) + strlen(value) + 2);

    if (string == NULL)
        return NULL;
    string[0] = '\0';
    strcat(string, key);
    strcat(string, "=");
    strcat(string, value);
    return string;
}

bool shell_set_env_var(shell_t *shell, const char *key, const char *value)
{
    char *string = create_string(key, value);
    size_t index = shell_find_env_var(shell, key);
    char **array;

    if (string == NULL)
        return false;
    if (shell->env[index] != NULL) {
        free(shell->env[index]);
        shell->env[index] = string;
    } else {
        array = realloc(shell->env, sizeof(char *) * (index + 2));
        if (array == NULL) {
            free(string);
            return false;
        }
        shell->env = array;
        shell->env[index] = string;
        shell->env[index + 1] = NULL;
    }
    return true;
}
