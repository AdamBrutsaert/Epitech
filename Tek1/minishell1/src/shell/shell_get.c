/*
** EPITECH PROJECT, 2023
** shell_get.c
** File description:
** shell_get.c
*/

#include "shell.h"
#include "my/string.h"

#include <stddef.h>

char *shell_get(shell_t *shell, char const *name)
{
    uint64_t length = my_strlen(name);

    for (char **env = shell->env; *env; env++) {
        if (!my_strncmp(*env, name, length) && (*env)[length] == '=')
            return my_strdup(*env + length + 1);
    }
    return NULL;
}
