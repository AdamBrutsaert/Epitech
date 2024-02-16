/*
** EPITECH PROJECT, 2023
** parser_is_comment.c
** File description:
** parser_is_comment.c
*/

#include "lem_in/parser_impl.h"

bool parser_is_comment(parser_t *parser)
{
    return parser->line[0] == '#';
}
