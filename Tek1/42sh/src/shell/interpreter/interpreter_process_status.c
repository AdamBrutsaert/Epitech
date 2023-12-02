/*
** EPITECH PROJECT, 2023
** interpreter_process_status.c
** File description:
** interpreter_process_status.c
*/

#include "shell/interpreter_impl.h"
#include "shell.h"

#include <stdio.h>
#include <sys/wait.h>

void interpreter_process_status(struct shell *shell, int status)
{
    shell_set_status(shell, WEXITSTATUS(status));
    if (!WIFSIGNALED(status))
        return;
    if (WTERMSIG(status) == SIGPIPE)
        return;
    shell_set_status(shell, 128 + WTERMSIG(status));
    if (WTERMSIG(status) == SIGSEGV) {
        fprintf(stderr, "Segmentation fault%s\n",
            WCOREDUMP(status) ? " (core dumped)" : "");
    }
    if (WTERMSIG(status) == SIGFPE) {
        fprintf(stderr, "Floating exception%s\n",
            WCOREDUMP(status) ? " (core dumped)" : "");
    }
}
