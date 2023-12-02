/*
** EPITECH PROJECT, 2023
** expression_get_program_path.c
** File description:
** expression_get_program_path.c
*/

#include "expression.h"
#include "shell.h"
#include "my/error.h"
#include "my/stdio.h"

#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

char *expression_get_program_path(shell_t *shell, char *name)
{
    struct stat stats;
    char *program = shell_find_binary(shell, name);

    if (ERROR != OK)
        THROW_NULL(ERROR);
    if (program == NULL) {
        my_eputs(name);
        my_eputs(": Command not found.\n");
        shell->status = 1;
        return NULL;
    }
    stat(program, &stats);
    if (S_ISDIR(stats.st_mode) || access(program, X_OK) != 0) {
        my_eputs(name);
        my_eputs(": Permission denied.\n");
        free(program);
        shell->status = 1;
        return NULL;
    }
    return program;
}
