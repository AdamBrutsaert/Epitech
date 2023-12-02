/*
** EPITECH PROJECT, 2023
** compiler_write_indirect_label.c
** File description:
** compiler_write_indirect_label.c
*/

#include "asm/compiler_impl.h"
#include "asm/conversion.h"

#include <unistd.h>

bool compiler_write_indirect_label(compiler_t *compiler, token_t *token,
                                    operation_t *operation)
{
    char *label = string_to_cstr(compiler->scratch,
        string_slice(compiler->scratch, token->value, 1,
            string_get_length(token->value)));
    size_t *offset = map_get(compiler->labels, label);
    intmax_t value;

    if (offset == NULL) {
        compiler_error(compiler, token, "undefined label");
        return false;
    }
    value = intmax_to_big_endian(
        (intmax_t)*offset - (intmax_t)operation->offset);
    write(compiler->fd, &((int8_t *)&value)[sizeof(intmax_t) - IND_SIZE],
        IND_SIZE);
    return true;
}
