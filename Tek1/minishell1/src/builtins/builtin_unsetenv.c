/*
** EPITECH PROJECT, 2023
** builtin_unsetenv.c
** File description:
** builtin_unsetenv.c
*/

#include "builtins.h"
#include "my/string.h"
#include "my/stdio.h"

#include <stdint.h>
#include <stddef.h>

void builtin_unsetenv(shell_t *shell, char **arguments)
{
    if (my_strarrlen(arguments) == 1) {
        my_eputs("unsetenv: Too few arguments.\n");
        shell->status = 1;
    } else {
        for (uint64_t i = 1; arguments[i] != NULL; i++)
            shell_unset(shell, arguments[i]);
        shell->status = 0;
    }
}
