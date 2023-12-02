/*
** EPITECH PROJECT, 2023
** asm_process.c
** File description:
** asm_process.c
*/

#include "asm_impl.h"

bool asm_process(asm_t *asm, const char *filepath)
{
    reader_clear(asm->reader);
    lexer_clear(asm->lexer);
    if (!reader_push_file(asm->reader, filepath))
        return false;
    if (!lexer_process(asm->lexer, asm->reader, filepath))
        return false;
    if (!compiler_process(asm->compiler, asm->lexer, filepath))
        return false;
    return true;
}
