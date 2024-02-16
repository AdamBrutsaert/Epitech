/*
** EPITECH PROJECT, 2023
** compiler_write_types.c
** File description:
** compiler_write_types.c
*/

#include "asm/compiler_impl.h"

#include <unistd.h>

static int8_t get_arg_type(token_t *token)
{
    token_type_t type;

    if (token == NULL)
        return 0;
    type = token->type;
    if (type == TOKEN_REGISTER)
        return 1;
    if (type == TOKEN_DIRECT_VALUE || type == TOKEN_DIRECT_LABEL)
        return 2;
    if (type == TOKEN_INDIRECT_VALUE || type == TOKEN_INDIRECT_LABEL)
        return 3;
    return 0;
}

bool compiler_write_types(compiler_t *compiler, operation_t *operation)
{
    int8_t byte = 0;
    char *mnemonique = string_to_cstr(compiler->scratch,
        operation->instruction->value);

    if (!my_strcmp(mnemonique, "live") || !my_strcmp(mnemonique, "zjmp") ||
        !my_strcmp(mnemonique, "fork") || !my_strcmp(mnemonique, "lfork"))
        return true;
    for (size_t i = 0; i < operation->args_count; i++)
        byte += get_arg_type(operation->args[i]) << (6 - (i * 2));
    write(compiler->fd, &byte, sizeof(int8_t));
    return true;
}
