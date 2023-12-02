/*
** EPITECH PROJECT, 2023
** compiler_write_register.c
** File description:
** compiler_write_register.c
*/

#include "asm/compiler_impl.h"
#include "asm/conversion.h"

#include <unistd.h>

bool compiler_write_register(compiler_t *compiler, token_t *token)
{
    string_t *number = string_slice(compiler->scratch, token->value, 1,
        string_get_length(token->value));
    intmax_t value = string_to_int(number);

    if (value <= 0 || value > REG_NUMBER) {
        compiler_error(compiler, token, "invalid register number");
        return false;
    }
    value = intmax_to_big_endian(string_to_int(number));
    write(compiler->fd, &((int8_t *)&value)[sizeof(intmax_t) - 1], 1);
    return true;
}
