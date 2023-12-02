/*
** EPITECH PROJECT, 2023
** compiler_write_operations.c
** File description:
** compiler_write_operations.c
*/

#include "asm/compiler_impl.h"

static bool write_operation(compiler_t *compiler, operation_t *operation)
{
    if (!compiler_write_instruction(compiler, operation))
        return false;
    compiler_write_types(compiler, operation);
    if (!compiler_write_arguments(compiler, operation))
        return false;
    return true;
}

bool compiler_write_operations(compiler_t *compiler)
{
    for (size_t i = 0; i < VEC_LEN(compiler->operations); i++)
        if (!write_operation(compiler,
                &VEC_GET(compiler->operations, operation_t, i)))
            return false;
    return true;
}
