/*
** EPITECH PROJECT, 2023
** asm_new.c
** File description:
** asm_new.c
*/

#include "asm_impl.h"
#include "my/memory.h"

asm_t *asm_new(void)
{
    asm_t *asm = my_malloc(sizeof(asm_t));

    asm->reader = reader_new();
    asm->lexer = lexer_new();
    asm->compiler = compiler_new();
    return asm;
}
