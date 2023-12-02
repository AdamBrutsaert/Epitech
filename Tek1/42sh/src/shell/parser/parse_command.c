/*
** EPITECH PROJECT, 2023
** parse_command.c
** File description:
** parse_command.c
*/

#include "shell/parser_impl.h"

command_t *parse_command(lexer_t *lexer)
{
    command_t *command = command_new();
    pipeline_t *pipeline;

    if (command == NULL)
        return NULL;
    while (lexer_peek_type(lexer, 0) != TOKEN_END
        && lexer_peek_type(lexer, 0) != TOKEN_NEWLINE) {
        pipeline = parse_pipeline(lexer);
        if (pipeline == NULL || !command_push_pipeline(command, pipeline)) {
            pipeline_delete(pipeline);
            command_delete(command);
            return NULL;
        }
    }
    if (lexer_peek_type(lexer, 0) == TOKEN_NEWLINE)
        lexer_next(lexer);
    return command;
}
