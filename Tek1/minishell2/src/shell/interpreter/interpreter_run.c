/*
** EPITECH PROJECT, 2023
** interpreter_run.c
** File description:
** interpreter_run.c
*/

#include "shell/interpreter.h"
#include "my/stdio.h"

#include <unistd.h>

static void process(interpreter_t *interpreter)
{
    command_t *command = parser_process(interpreter->parser);

    if (command == NULL) {
        if (!parser_is_eof(interpreter->parser)) {
            interpreter_set_status(interpreter, 1);
        }
        return;
    }
    interpreter_execute_command(interpreter, command);
    command_destroy(command);
}

static void repl(interpreter_t *interpreter)
{
    while (!parser_is_eof(interpreter->parser) && !interpreter->exit) {
        my_puts("$> ");
        process(interpreter);
    }
    if (!interpreter->exit)
        my_eputs("exit\n");
}

static void process_input(interpreter_t *interpreter)
{
    while (!parser_is_eof(interpreter->parser) && !interpreter->exit)
        process(interpreter);
}

int interpreter_run(interpreter_t *interpreter)
{
    if (isatty(STDIN_FILENO)) {
        repl(interpreter);
    } else {
        process_input(interpreter);
    }
    return interpreter->status;
}
