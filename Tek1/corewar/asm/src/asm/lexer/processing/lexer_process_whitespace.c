/*
** EPITECH PROJECT, 2023
** lexer_process_whitespace.c
** File description:
** lexer_process_whitespace.c
*/

#include "asm/lexer_impl.h"

bool lexer_process_whitespace(
    __attribute__((unused)) lexer_t *lexer,
    reader_t *reader
)
{
    reader_next(reader, 1);
    return true;
}
