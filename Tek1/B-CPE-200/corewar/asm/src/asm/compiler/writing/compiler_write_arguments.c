/*
** EPITECH PROJECT, 2023
** compiler_write_arguments.c
** File description:
** compiler_write_arguments.c
*/

#include "asm/compiler_impl.h"

static bool write_argument(compiler_t *compiler, token_t *token,
                            operation_t *operation)
{
    if (token->type == TOKEN_DIRECT_VALUE)
        return compiler_write_direct_value(compiler, token, operation);
    if (token->type == TOKEN_DIRECT_LABEL)
        return compiler_write_direct_label(compiler, token, operation);
    if (token->type == TOKEN_INDIRECT_VALUE)
        return compiler_write_indirect_value(compiler, token);
    if (token->type == TOKEN_INDIRECT_LABEL)
        return compiler_write_indirect_label(compiler, token, operation);
    if (token->type == TOKEN_REGISTER)
        return compiler_write_register(compiler, token);
    return false;
}

bool compiler_write_arguments(compiler_t *compiler, operation_t *operation)
{
    for (size_t i = 0; i < operation->args_count; i++) {
        if (!write_argument(compiler, operation->args[i], operation))
            return false;
    }
    return true;
}
