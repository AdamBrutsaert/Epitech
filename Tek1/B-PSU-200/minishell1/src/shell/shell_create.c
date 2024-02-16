/*
** EPITECH PROJECT, 2023
** shell_create.c
** File description:
** shell_create.c
*/

#include "shell.h"
#include "my/string.h"
#include "my/error.h"

#include <stdlib.h>

shell_t *shell_create(char **env)
{
    shell_t *shell = malloc(sizeof(shell_t));

    if (shell == NULL)
        THROW_NULL(ERROR_ALLOCATION);
    shell->env = my_strarrdup(env);
    if (ERROR != OK) {
        free(shell);
        THROW_NULL(ERROR);
    }
    shell->exit = false;
    shell->status = 0;
    return shell;
}
