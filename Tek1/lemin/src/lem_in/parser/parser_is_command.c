/*
** EPITECH PROJECT, 2023
** parser_is_command.c
** File description:
** parser_is_command.c
*/

#include "lem_in/parser_impl.h"

bool parser_is_command(parser_t *parser)
{
    return parser->line[0] == '#' && parser->line[1] == '#';
}
