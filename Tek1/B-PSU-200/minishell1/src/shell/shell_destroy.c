/*
** EPITECH PROJECT, 2023
** shell_destroy.c
** File description:
** shell_destroy.c
*/

#include "shell.h"
#include "my/string.h"

#include <stdlib.h>

void shell_destroy(shell_t *shell)
{
    my_strarrfree(shell->env);
    free(shell);
}
