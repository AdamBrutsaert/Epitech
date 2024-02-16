/*
** EPITECH PROJECT, 2023
** compiler_impl.h
** File description:
** compiler_impl.h
*/

#pragma once

#include "compiler.h"
#include "my/vector.h"
#include "map.h"
#include "op.h"

typedef struct {
    token_t *instruction;
    uint8_t args_count;
    token_t *args[MAX_ARGS_NUMBER];
    size_t offset;
} operation_t;

struct compiler {
    arena_t *scratch;
    const char *path;

    header_t header;
    map_t *labels;
    vec_t *operations;

    int fd;
};

char *compiler_get_output_path(arena_t *arena, const char *input);

// Utils
size_t compiler_get_operation_size(compiler_t *compiler,
                                    operation_t *operation);

// Errors
void compiler_error(compiler_t *compiler, token_t *token, const char *message);
void compiler_error_token(compiler_t *compiler, token_t *token);
void compiler_error_command(compiler_t *compiler, token_t *token);

// Checks
bool compiler_is_valid_operation(compiler_t *compiler, operation_t *operation);

// Processing
bool compiler_process_header(compiler_t *compiler, lexer_t *lexer);
bool compiler_process_operation(compiler_t *compiler, lexer_t *lexer);
bool compiler_process_label(compiler_t *compiler, lexer_t *lexer);
bool compiler_process_instruction(compiler_t *compiler, lexer_t *lexer,
                                operation_t *operation);
bool compiler_process_arguments(compiler_t *compiler, lexer_t *lexer,
                                operation_t *operation);

// Writing
bool compiler_write(compiler_t *compiler, const char *path);
void compiler_write_header(compiler_t *compiler);
bool compiler_write_operations(compiler_t *compiler);
bool compiler_write_instruction(compiler_t *compiler, operation_t *operation);
bool compiler_write_types(compiler_t *compiler, operation_t *operation);
bool compiler_write_arguments(compiler_t *compiler, operation_t *operation);
bool compiler_write_register(compiler_t *compiler, token_t *token);
bool compiler_write_direct_value(compiler_t *compiler, token_t *token,
                                operation_t *operation);
bool compiler_write_direct_label(compiler_t *compiler, token_t *token,
                                operation_t *operation);
bool compiler_write_indirect_value(compiler_t *compiler, token_t *token);
bool compiler_write_indirect_label(compiler_t *compiler, token_t *token,
                                    operation_t *operation);
