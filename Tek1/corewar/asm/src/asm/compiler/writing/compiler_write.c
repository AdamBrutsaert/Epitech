/*
** EPITECH PROJECT, 2023
** compiler_write.c
** File description:
** compiler_write.c
*/

#include "asm/compiler_impl.h"

#include <unistd.h>
#include <fcntl.h>

bool compiler_write(compiler_t *compiler, const char *path)
{
    char *output = compiler_get_output_path(compiler->scratch, path);

    compiler->fd = open(output, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (compiler->fd == -1)
        return false;
    compiler_write_header(compiler);
    if (!compiler_write_operations(compiler)) {
        close(compiler->fd);
        return false;
    }
    close(compiler->fd);
    return true;
}
