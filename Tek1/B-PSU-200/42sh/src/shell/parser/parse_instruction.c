/*
** EPITECH PROJECT, 2023
** parse_instruction.c
** File description:
** parse_instruction.c
*/

#include "shell/parser_impl.h"

static bool is_still_instruction(lexer_t *lexer)
{
    token_type_t type = lexer_peek_type(lexer, 0);

    return type != TOKEN_END
        && type != TOKEN_NEWLINE
        && type != TOKEN_SEMICOLON
        && type != TOKEN_DOUBLE_AMPERSAND
        && type != TOKEN_DOUBLE_PIPE
        && type != TOKEN_PIPE;
}

instruction_t *parse_instruction(lexer_t *lexer)
{
    instruction_t *instruction = instruction_new();

    if (instruction == NULL)
        return NULL;
    while (is_still_instruction(lexer)) {
        if (!parse_redirection(lexer, instruction)
            || !parse_argument(lexer, instruction)) {
            instruction_delete(instruction);
            return NULL;
        }
    }
    return instruction;
}
