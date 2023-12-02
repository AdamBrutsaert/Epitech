/*
** EPITECH PROJECT, 2023
** asm_delete.c
** File description:
** asm_delete.c
*/

#include "asm_impl.h"
#include "my/memory.h"

void asm_delete(asm_t *asm)
{
    reader_delete(asm->reader);
    lexer_delete(asm->lexer);
    compiler_delete(asm->compiler);
    my_free(asm);
}
