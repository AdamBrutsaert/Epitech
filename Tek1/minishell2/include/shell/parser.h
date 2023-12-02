/*
** EPITECH PROJECT, 2023
** parser.h
** File description:
** parser.h
*/

#pragma once

#include "lexer.h"
#include "command.h"

typedef struct {
    lexer_t *lexer;
} parser_t;

parser_t *parser_create(lexer_t *lexer);
void parser_destroy(parser_t *parser);

command_t *parser_process(parser_t *parser);
command_t *parser_process_command(parser_t *parser);
pipeline_t *parser_process_pipeline(parser_t *parser);
instruction_t *parser_process_instruction(parser_t *parser);

bool parser_is_eof(parser_t *parser);
