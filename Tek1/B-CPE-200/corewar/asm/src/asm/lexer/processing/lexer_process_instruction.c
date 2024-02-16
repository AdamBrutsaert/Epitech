/*
** EPITECH PROJECT, 2023
** lexer_process_instruction.c
** File description:
** lexer_process_instruction.c
*/

#include "asm/lexer_impl.h"
#include "asm/op.h"

bool lexer_process_instruction(
    lexer_t *lexer,
    reader_t *reader,
    string_t *string
)
{
    if (!lexer_is_valid_end_character(reader_peek(reader, 0))) {
        lexer_error_character(lexer, reader, reader_peek(reader, 0));
        return false;
    }
    lexer_push_token(lexer, reader, TOKEN_INSTRUCTION, string);
    return true;
}
