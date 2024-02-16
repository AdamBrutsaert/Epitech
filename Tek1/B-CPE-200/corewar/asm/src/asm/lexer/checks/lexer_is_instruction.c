/*
** EPITECH PROJECT, 2023
** lexer_is_instruction.c
** File description:
** lexer_is_instruction.c
*/

#include "asm/lexer_impl.h"
#include "asm/op.h"

bool lexer_is_instruction(const char *string)
{
    for (size_t i = 0; op_tab[i].mnemonique != 0; i++) {
        if (!my_strcmp(string, op_tab[i].mnemonique))
            return true;
    }
    return false;
}
