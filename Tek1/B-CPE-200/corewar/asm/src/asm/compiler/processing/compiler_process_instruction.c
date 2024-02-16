/*
** EPITECH PROJECT, 2023
** compiler_process_instruction.c
** File description:
** compiler_process_instruction.c
*/

#include "asm/compiler_impl.h"

bool compiler_process_instruction(__attribute__((unused)) compiler_t *compiler,
    lexer_t *lexer, operation_t *operation)
{
    token_t *token = lexer_next(lexer);

    if (token == NULL || token->type != TOKEN_INSTRUCTION) {
        compiler_error_token(compiler, token);
        return false;
    }
    operation->instruction = token;
    return true;
}
