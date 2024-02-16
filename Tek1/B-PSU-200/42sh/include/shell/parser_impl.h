/*
** EPITECH PROJECT, 2023
** parser_impl.h
** File description:
** parser_impl.h
*/

#pragma once

#include "parser.h"

command_t *parse_command(lexer_t *lexer);
pipeline_t *parse_pipeline(lexer_t *lexer);
instruction_t *parse_instruction(lexer_t *lexer);

separator_t parse_separator(lexer_t *lexer);
bool parse_redirection(lexer_t *lexer, instruction_t *instruction);
bool parse_argument(lexer_t *lexer, instruction_t *instruction);
