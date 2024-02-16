/*
** EPITECH PROJECT, 2023
** parse_pipeline.c
** File description:
** parse_pipeline.c
*/

#include "shell/parser_impl.h"

static bool is_still_pipeline(lexer_t *lexer)
{
    token_type_t type = lexer_peek_type(lexer, 0);

    return type != TOKEN_END
        && type != TOKEN_NEWLINE
        && type != TOKEN_SEMICOLON
        && type != TOKEN_DOUBLE_AMPERSAND
        && type != TOKEN_DOUBLE_PIPE;
}

static bool process_instruction(lexer_t *lexer, pipeline_t *pipeline)
{
    instruction_t *instruction = parse_instruction(lexer);

    if (instruction == NULL)
        return false;
    if (!pipeline_push_instruction(pipeline, instruction)) {
        instruction_delete(instruction);
        return false;
    }
    return true;
}

pipeline_t *parse_pipeline(lexer_t *lexer)
{
    pipeline_t *pipeline = pipeline_new();
    bool expecting = false;

    if (pipeline == NULL)
        return false;
    pipeline_set_separator(pipeline, parse_separator(lexer));
    while (is_still_pipeline(lexer) || expecting) {
        expecting = false;
        if (!process_instruction(lexer, pipeline)) {
            pipeline_delete(pipeline);
            return NULL;
        }
        if (lexer_peek_type(lexer, 0) == TOKEN_PIPE) {
            expecting = true;
            lexer_next(lexer);
        }
    }
    return pipeline;
}
