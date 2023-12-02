/*
** EPITECH PROJECT, 2023
** compiler_write_indirect_value.c
** File description:
** compiler_write_indirect_value.c
*/

#include "asm/compiler_impl.h"
#include "asm/conversion.h"

#include <unistd.h>

bool compiler_write_indirect_value(compiler_t *compiler, token_t *token)
{
    intmax_t value = intmax_to_big_endian(string_to_int(token->value));

    write(compiler->fd, &((int8_t *)&value)[sizeof(intmax_t) - IND_SIZE],
        IND_SIZE);
    return true;
}
