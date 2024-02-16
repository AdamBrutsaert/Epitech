/*
** EPITECH PROJECT, 2023
** shell_copy_env.c
** File description:
** shell_copy_env.c
*/

#include "shell_impl.h"
#include "my/memory.h"

#include <stdlib.h>
#include <string.h>

bool shell_copy_env(shell_t *shell, char **envp)
{
    size_t length = my_array_length(envp);
    char **env = malloc(sizeof(char *) * (length + 1));

    if (env == NULL)
        return false;
    for (size_t i = 0; i < length; i++) {
        env[i] = strdup(envp[i]);
        if (env[i] == NULL) {
            my_array_free(env);
            return false;
        }
    }
    env[length] = NULL;
    my_array_free(shell->env);
    shell->env = env;
    return true;
}
