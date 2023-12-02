/*
** EPITECH PROJECT, 2023
** compiler_get_operation_size.c
** File description:
** compiler_get_operation_size.c
*/

#include "asm/compiler_impl.h"

static size_t get_arg_size(char *mnemonique, token_t *token)
{
    if (!my_strcmp(mnemonique, "zjmp") || !my_strcmp(mnemonique, "fork")
        || !my_strcmp(mnemonique, "lfork"))
        return 2;
    if (token->type == TOKEN_REGISTER)
        return 1;
    if (token->type == TOKEN_INDIRECT_VALUE
            || token->type == TOKEN_INDIRECT_LABEL
            || !my_strcmp(mnemonique, "sti") || !my_strcmp(mnemonique, "ldi")
            || !my_strcmp(mnemonique, "lldi"))
        return IND_SIZE;
    if (token->type == TOKEN_DIRECT_VALUE
            || token->type == TOKEN_DIRECT_LABEL)
        return DIR_SIZE;
    return 0;
}

size_t compiler_get_operation_size(compiler_t *compiler, operation_t *operation)
{
    size_t size = 1;
    char *mnemonique = string_to_cstr(compiler->scratch,
        operation->instruction->value);

    if (my_strcmp(mnemonique, "live") && my_strcmp(mnemonique, "zjmp")
        && my_strcmp(mnemonique, "fork") && my_strcmp(mnemonique, "lfork"))
        size++;
    for (size_t i = 0; i < operation->args_count; i++)
        size += get_arg_size(mnemonique, operation->args[i]);
    return size;
}
