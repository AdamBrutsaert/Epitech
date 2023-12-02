/*
** EPITECH PROJECT, 2023
** compiler_process_operation.c
** File description:
** compiler_process_operation.c
*/

#include "asm/compiler_impl.h"

static void set_operation_offset(compiler_t *compiler, operation_t *operation)
{
    size_t length = VEC_LEN(compiler->operations);
    operation_t *last;

    if (length == 0) {
        operation->offset = 0;
    } else {
        last = vec_get(compiler->operations, length - 1);
        operation->offset = last->offset
            + compiler_get_operation_size(compiler, last);
    }
}

bool compiler_process_operation(compiler_t *compiler, lexer_t *lexer)
{
    operation_t operation;

    if (lexer_peek_type(lexer, 0) == TOKEN_LABEL
        && !compiler_process_label(compiler, lexer))
        return false;
    if (lexer_is_end_of_line(lexer))
        return true;
    if (!compiler_process_instruction(compiler, lexer, &operation))
        return false;
    if (!compiler_process_arguments(compiler, lexer, &operation))
        return false;
    if (!compiler_is_valid_operation(compiler, &operation))
        return false;
    if (!lexer_is_end_of_line(lexer))
        return false;
    set_operation_offset(compiler, &operation);
    VEC_PUSH(compiler->operations, operation);
    return true;
}
