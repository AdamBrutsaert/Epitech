/*
** EPITECH PROJECT, 2023
** parser_process_instruction.c
** File description:
** parser_process_instruction.c
*/

#include "shell/parser.h"

static bool is_still_instruction(parser_t *parser)
{
    token_t *token = lexer_peek(parser->lexer);

    return token->type != TOKEN_END
        && token->type != TOKEN_NEWLINE
        && token->type != TOKEN_SEMICOLON
        && token->type != TOKEN_PIPE;
}

static bool is_redirect(parser_t *parser)
{
    token_t *token = lexer_peek(parser->lexer);

    return token->type == TOKEN_LEFT_CHEVRON
        || token->type == TOKEN_DOUBLE_LEFT_CHEVRON
        || token->type == TOKEN_RIGHT_CHEVRON
        || token->type == TOKEN_DOUBLE_RIGHT_CHEVRON;
}

static bool parse_redirect(parser_t *parser, instruction_t *instruction)
{
    token_t *first = lexer_peek(parser->lexer);
    token_t *second;
    redirect_type_t type;

    if (!is_redirect(parser))
        return true;
    lexer_next(parser->lexer);
    second = lexer_next(parser->lexer);
    if (second->type != TOKEN_STRING)
        return false;
    if (first->type == TOKEN_LEFT_CHEVRON)
        type = REDIRECT_INPUT;
    if (first->type == TOKEN_DOUBLE_LEFT_CHEVRON)
        type = REDIRECT_HERE_DOCUMENT;
    if (first->type == TOKEN_RIGHT_CHEVRON)
        type = REDIRECT_OUTPUT;
    if (first->type == TOKEN_DOUBLE_RIGHT_CHEVRON)
        type = REDIRECT_APPEND;
    return instruction_add_redirect(instruction, type, second->value);
}

static bool parse_argument(parser_t *parser, instruction_t *instruction)
{
    token_t *token = lexer_peek(parser->lexer);

    if (token->type != TOKEN_STRING)
        return true;
    lexer_next(parser->lexer);
    return instruction_add_argument(instruction, token->value);
}

instruction_t *parser_process_instruction(parser_t *parser)
{
    instruction_t *instruction = instruction_create();

    if (instruction == NULL)
        return NULL;
    while (is_still_instruction(parser)) {
        if (!parse_redirect(parser, instruction)
            || !parse_argument(parser, instruction)) {
            instruction_destroy(instruction);
            return NULL;
        }
    }
    return instruction;
}
