/*
** EPITECH PROJECT, 2023
** lexer_process_direct.c
** File description:
** lexer_process_direct.c
*/

#include "asm/lexer_impl.h"
#include "asm/op.h"

bool lexer_process_direct(lexer_t *lexer, reader_t *reader)
{
    if (reader_peek(reader, 1) == LABEL_CHAR)
        return lexer_process_direct_label(lexer, reader);
    return lexer_process_direct_value(lexer, reader);
}
