/*
** EPITECH PROJECT, 2023
** interpreter_process_status.c
** File description:
** interpreter_process_status.c
*/

#include "shell/interpreter.h"

#include "my/stdio.h"

#include <sys/wait.h>

void interpreter_process_status(interpreter_t *interpreter, int status)
{
    interpreter_set_status(interpreter, WEXITSTATUS(status));
    if (!WIFSIGNALED(status))
        return;
    if (WTERMSIG(status) == SIGPIPE)
        return;
    interpreter_set_status(interpreter, 128 + WTERMSIG(status));
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
