/*
** EPITECH PROJECT, 2023
** expression_process_status.c
** File description:
** expression_process_status.c
*/

#include "expression.h"
#include "my/stdio.h"

#include <sys/wait.h>

void expression_process_status(shell_t *shell, int status)
{
    shell->status = WEXITSTATUS(status);

    if (!WIFSIGNALED(status))
        return;
    shell->status = 128 + WTERMSIG(status);
    if (WTERMSIG(status) == SIGSEGV) {
        my_eputs("Segmentation fault");
        if (WCOREDUMP(status))
            my_eputs(" (core dumped)");
        my_eputs("\n");
    }
    if (WTERMSIG(status) == SIGFPE) {
        my_eputs("Floating exception");
        if (WCOREDUMP(status))
            my_eputs(" (core dumped)");
        my_eputs("\n");
    }
}
