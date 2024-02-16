/*
** EPITECH PROJECT, 2023
** compiler_write_header.c
** File description:
** compiler_write_header.c
*/

#include "asm/compiler_impl.h"
#include "asm/conversion.h"

#include <unistd.h>

static int get_prog_size(compiler_t *compiler)
{
    size_t length = VEC_LEN(compiler->operations);
    operation_t *last;

    if (length == 0)
        return 0;
    last = vec_get(compiler->operations, length - 1);
    return last->offset + compiler_get_operation_size(compiler, last);
}

void compiler_write_header(compiler_t *compiler)
{
    compiler->header.magic = int_to_big_endian(compiler->header.magic);
    compiler->header.prog_size = int_to_big_endian(get_prog_size(compiler));
    write(compiler->fd, &compiler->header, sizeof(header_t));
}
