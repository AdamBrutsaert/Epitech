/*
** EPITECH PROJECT, 2023
** compiler_process_arguments.c
** File description:
** compiler_process_arguments.c
*/

#include "asm/compiler_impl.h"

static bool is_argument(token_type_t type)
{
    return type == TOKEN_REGISTER
        || type == TOKEN_DIRECT_VALUE
        || type == TOKEN_DIRECT_LABEL
        || type == TOKEN_INDIRECT_LABEL
        || type == TOKEN_INDIRECT_VALUE;
}

static bool process_argument(compiler_t *compiler, token_t *token,
    operation_t *operation, size_t index)
{
    if (index >= MAX_ARGS_NUMBER) {
        compiler_error(compiler, token, "too many arguments");
        return false;
    }
    operation->args[index] = token;
    operation->args_count = index + 1;
    return true;
}

bool compiler_process_arguments(__attribute__((unused)) compiler_t *compiler,
    lexer_t *lexer, operation_t *operation)
{
    size_t index = 0;
    bool expecting = true;

    while (is_argument(lexer_peek_type(lexer, 0))) {
        expecting = false;
        if (!process_argument(compiler, lexer_next(lexer), operation, index))
            return false;
        index++;
        if (lexer_peek_type(lexer, 0) == TOKEN_SEPARATOR) {
            expecting = true;
            lexer_next(lexer);
        }
    }
    if (expecting) {
        compiler_error(compiler, lexer_peek(lexer, 0),
            "expected argument");
        return false;
    }
    return true;
}
