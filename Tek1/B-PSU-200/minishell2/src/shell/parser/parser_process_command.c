/*
** EPITECH PROJECT, 2023
** parser_process_command.c
** File description:
** parser_process_command.c
*/

#include "shell/parser.h"

static bool process_pipeline(parser_t *parser, command_t *command)
{
    pipeline_t *pipeline = parser_process_pipeline(parser);

    return pipeline && command_add_pipeline(command, pipeline);
}

command_t *parser_process_command(parser_t *parser)
{
    command_t *command = command_create();

    if (command == NULL)
        return NULL;
    while (lexer_peek(parser->lexer)->type != TOKEN_END) {
        if (!process_pipeline(parser, command)) {
            command_destroy(command);
            return NULL;
        }
    }
    return command;
}
