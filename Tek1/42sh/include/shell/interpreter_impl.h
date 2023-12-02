/*
** EPITECH PROJECT, 2023
** interpreter_impl.h
** File description:
** interpreter_impl.h
*/

#pragma once

#include "interpreter.h"
#include "my/vector.h"
#include "shell.h"

struct interpreter {
    shell_t *shell;
    pipeline_t *pipeline;
    instruction_t *instruction;
    size_t instruction_index;

    vec_t *processes;
    vec_t *pipes;
    int stdout_copy;
    int stdin_copy;
};

void interpreter_process_pipeline(interpreter_t *interpreter);
bool interpreter_process_instruction(interpreter_t *interpreter);
void interpreter_wait_processes(interpreter_t *interpreter);

// create / close useless pipes
void interpreter_create_pipe(interpreter_t *interpreter);
void interpreter_close_pipe(interpreter_t *interpreter);

// redirections inside forked child
void interpreter_handle_pipes(interpreter_t *interpreter);
void interpreter_handle_builtin_pipes(interpreter_t *interpreter);

bool interpreter_handle_redirections(interpreter_t *interpreter);
bool interpreter_handle_input(
    interpreter_t *interpreter,
    redirection_t *redirection
);
bool interpreter_handle_output(
    interpreter_t *interpreter,
    redirection_t *redirection
);
bool interpreter_handle_append(
    interpreter_t *interpreter,
    redirection_t *redirection
);
bool interpreter_handle_here_document(
    interpreter_t *interpreter,
    redirection_t *redirection
);
void interpreter_remove_redirections(interpreter_t *interpreter);

void interpreter_execute_program(interpreter_t *interpreter);
void interpreter_process_status(struct shell *shell, int status);
