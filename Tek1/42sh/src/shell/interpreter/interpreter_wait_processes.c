/*
** EPITECH PROJECT, 2023
** interpreter_wait_processes.c
** File description:
** interpreter_wait_processes.c
*/

#include "shell/interpreter_impl.h"

#include <sys/wait.h>

void interpreter_wait_processes(interpreter_t *interpreter)
{
    pid_t pid;
    int status;

    for (size_t i = 0; i < VEC_LEN(interpreter->processes); i++) {
        pid = VEC_GET(interpreter->processes, i, pid_t);
        if (pid != -1) {
            waitpid(pid, &status, 0);
            interpreter_process_status(interpreter->shell, status);
        }
    }
}
