/*
** EPITECH PROJECT, 2023
** compiler_new.c
** File description:
** compiler_new.c
*/

#include "asm/compiler_impl.h"
#include "my/memory.h"

compiler_t *compiler_new(void)
{
    compiler_t *compiler = my_malloc(sizeof(compiler_t));

    compiler->scratch = arena_new();
    compiler->labels = map_new();
    compiler->operations = vec_new(sizeof(operation_t));
    my_memset(&compiler->header, 0, sizeof(header_t));
    return compiler;
}
