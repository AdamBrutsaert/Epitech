/*
** EPITECH PROJECT, 2023
** parser_process_pipeline.c
** File description:
** parser_process_pipeline.c
*/

#include "shell/parser.h"
#include "my/stdio.h"

static bool is_still_pipeline(parser_t *parser)
{
    token_t *token = lexer_peek(parser->lexer);

    return token->type != TOKEN_END
        && token->type != TOKEN_NEWLINE
        && token->type != TOKEN_SEMICOLON;
}

static void parse_separator(parser_t *parser, pipeline_t *pipeline)
{
    token_t *token = lexer_peek(parser->lexer);

    if (token->type == TOKEN_NEWLINE) {
        pipeline->separator = SEPARATOR_NEWLINE;
        lexer_next(parser->lexer);
    }
    if (token->type == TOKEN_SEMICOLON) {
        pipeline->separator = SEPARATOR_SEMICOLON;
        lexer_next(parser->lexer);
    }
}

static bool parse_instruction(parser_t *parser, pipeline_t *pipeline)
{
    instruction_t *instruction = parser_process_instruction(parser);

    return instruction && pipeline_add_instruction(pipeline, instruction);
}

pipeline_t *parser_process_pipeline(parser_t *parser)
{
    pipeline_t *pipeline = pipeline_create();
    bool expecting = false;

    if (pipeline == NULL)
        return NULL;
    parse_separator(parser, pipeline);
    while (is_still_pipeline(parser) || expecting) {
        expecting = false;
        if (!parse_instruction(parser, pipeline)) {
            pipeline_destroy(pipeline);
            return NULL;
        }
        if (lexer_peek(parser->lexer)->type == TOKEN_PIPE) {
            expecting = true;
            lexer_next(parser->lexer);
        }
    }
    return pipeline;
}
