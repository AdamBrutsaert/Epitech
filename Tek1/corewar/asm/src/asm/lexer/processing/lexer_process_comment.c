/*
** EPITECH PROJECT, 2023
** lexer_process_comment.c
** File description:
** lexer_process_comment.c
*/

#include "asm/lexer_impl.h"

bool lexer_process_comment(
    __attribute__((unused)) lexer_t *lexer,
    reader_t *reader
)
{
    reader_skip_line(reader);
    return true;
}
