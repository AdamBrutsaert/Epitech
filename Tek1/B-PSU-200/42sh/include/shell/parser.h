/*
** EPITECH PROJECT, 2023
** parser.h
** File description:
** parser.h
*/

#pragma once

#include "command.h"
#include "lexer.h"

command_t *parse(lexer_t *lexer);
