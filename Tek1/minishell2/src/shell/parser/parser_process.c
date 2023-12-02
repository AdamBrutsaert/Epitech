/*
** EPITECH PROJECT, 2023
** parser_process.c
** File description:
** parser_process.c
*/

#include "shell/parser.h"

command_t *parser_process(parser_t *parser)
{
    command_t *command;

    if (!lexer_process(parser->lexer) || lexer_is_eof(parser->lexer))
        return NULL;
    command = parser_process_command(parser);
    if (command == NULL)
        return NULL;
    if (!command_check(command)) {
        command_destroy(command);
        return NULL;
    }
    return command;
}
