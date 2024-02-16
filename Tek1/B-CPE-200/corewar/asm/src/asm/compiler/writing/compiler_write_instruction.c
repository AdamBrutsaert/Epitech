/*
** EPITECH PROJECT, 2023
** compiler_write_instruction.c
** File description:
** compiler_write_instruction.c
*/

#include "asm/compiler_impl.h"

#include <unistd.h>

bool compiler_write_instruction(compiler_t *compiler, operation_t *operation)
{
    op_t *op = NULL;
    char *mnemonique = string_to_cstr(compiler->scratch,
        operation->instruction->value);

    for (size_t i = 0; op_tab[i].mnemonique; i++) {
        if (!my_strcmp(op_tab[i].mnemonique, mnemonique)) {
            op = &op_tab[i];
            break;
        }
    }
    if (!op)
        return false;
    write(compiler->fd, &op->code, sizeof(char));
    return true;
}
