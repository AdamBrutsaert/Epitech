/*
** EPITECH PROJECT, 2023
** compiler_write_direct_value.c
** File description:
** compiler_write_direct_value.c
*/

#include "asm/compiler_impl.h"
#include "asm/conversion.h"

#include <unistd.h>

static bool is_special(compiler_t *compiler, operation_t *operation)
{
    char *mnemonique = string_to_cstr(compiler->scratch,
        operation->instruction->value);

    if (!my_strcmp(mnemonique, "zjmp") || !my_strcmp(mnemonique, "fork")
        || !my_strcmp(mnemonique, "lfork") || !my_strcmp(mnemonique, "sti")
        || !my_strcmp(mnemonique, "ldi") || !my_strcmp(mnemonique, "lldi"))
        return true;
    return false;
}

bool compiler_write_direct_value(compiler_t *compiler, token_t *token,
                                operation_t *operation)
{
    string_t *number = string_slice(compiler->scratch, token->value, 1,
        string_get_length(token->value));
    intmax_t value = intmax_to_big_endian(string_to_int(number));

    if (is_special(compiler, operation)) {
        write(compiler->fd, &((int8_t *)&value)[sizeof(intmax_t) - IND_SIZE],
            IND_SIZE);
    } else {
        write(compiler->fd, &((int8_t *)&value)[sizeof(intmax_t) - DIR_SIZE],
            DIR_SIZE);
    }
    return true;
}
