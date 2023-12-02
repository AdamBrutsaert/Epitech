/*
** EPITECH PROJECT, 2023
** compiler_process.c
** File description:
** compiler_process.c
*/

#include "asm/compiler_impl.h"

bool compiler_process(compiler_t *compiler, lexer_t *lexer, const char *path)
{
    compiler->path = path;
    if (!compiler_process_header(compiler, lexer))
        return false;
    lexer_skip_newlines(lexer);
    while (lexer_peek_type(lexer, 0) != TOKEN_EOF) {
        if (!compiler_process_operation(compiler, lexer))
            return false;
        lexer_skip_newlines(lexer);
    }
    if (!compiler_write(compiler, path))
        return false;
    arena_clear(compiler->scratch);
    return true;
}
