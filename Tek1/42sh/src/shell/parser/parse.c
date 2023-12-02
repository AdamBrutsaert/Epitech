/*
** EPITECH PROJECT, 2023
** parse.c
** File description:
** parse.c
*/

#include "shell/parser_impl.h"

static void skip_current_command(lexer_t *lexer)
{
    while (lexer_peek_type(lexer, 0) != TOKEN_NEWLINE
        && lexer_peek_type(lexer, 0) != TOKEN_END)
        lexer_next(lexer);
    lexer_next(lexer);
}

command_t *parse(lexer_t *lexer)
{
    command_t *command = parse_command(lexer);

    if (command == NULL)
        skip_current_command(lexer);
    if (!command_check(command)) {
        command_delete(command);
        return NULL;
    }
    return command;
}
