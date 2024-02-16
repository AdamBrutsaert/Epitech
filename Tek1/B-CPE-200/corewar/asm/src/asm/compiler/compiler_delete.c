/*
** EPITECH PROJECT, 2023
** compiler_delete.c
** File description:
** compiler_delete.c
*/

#include "asm/compiler_impl.h"
#include "my/memory.h"

void compiler_delete(compiler_t *compiler)
{
    map_delete(compiler->labels);
    vec_delete(compiler->operations);
    arena_delete(compiler->scratch);
    my_free(compiler);
}
