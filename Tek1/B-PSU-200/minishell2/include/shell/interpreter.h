/*
** EPITECH PROJECT, 2023
** interpreter.h
** File description:
** interpreter.h
*/

#pragma once

#include "parser.h"

typedef struct {
    reader_t *reader;
    lexer_t *lexer;
    parser_t *parser;
    char **env;
    int status;
    bool exit;
} interpreter_t;

interpreter_t *interpreter_create(int argc, char **argv, char **envp);
void interpreter_destroy(interpreter_t *interpreter);

int interpreter_run(interpreter_t *interpreter);

void interpreter_execute_command(
    interpreter_t *interpreter,
    command_t *command
);
void interpreter_execute_pipeline(
    interpreter_t *interpreter,
    pipeline_t *pipeline
);
bool interpreter_execute_instruction(
    interpreter_t *interpreter,
    pipeline_t *pipeline,
    size_t index
);
void interpreter_execute_program(
    interpreter_t *interpreter,
    instruction_t *instruction
);
void interpreter_handle_pipes(
    pipeline_t *pipeline,
    size_t index
);
void interpreter_handle_builtin_pipes(
    pipeline_t *pipeline,
    size_t index
);
void interpreter_process_status(
    interpreter_t *interpreter,
    int status
);

bool interpreter_process_redirects(instruction_t *instruction);
void interpreter_remove_redirects(instruction_t *instruction);
bool interpreter_process_output(
    instruction_t *instruction,
    redirect_t *redirect
);
bool interpreter_process_append(
    instruction_t *instruction,
    redirect_t *redirect
);
bool interpreter_process_input(
    instruction_t *instruction,
    redirect_t *redirect
);
bool interpreter_process_here_document(
    instruction_t *instruction,
    redirect_t *redirect
);

char *interpreter_get_env_value(interpreter_t *interpreter, const char *name);
char **interpreter_get_path_directories(interpreter_t *interpreter);
char *interpreter_get_program_path(
    interpreter_t *interpreter,
    const char *name
);

void interpreter_set_status(
    interpreter_t *interpreter,
    int status
);
bool interpreter_set_env(
    interpreter_t *interpreter,
    const char *name,
    const char *value
);
void interpreter_unset_env(
    interpreter_t *interpreter,
    const char *name
);
