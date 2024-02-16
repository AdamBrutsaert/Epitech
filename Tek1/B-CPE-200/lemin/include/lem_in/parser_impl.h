/*
** EPITECH PROJECT, 2023
** parser_impl.h
** File description:
** parser_impl.h
*/

#pragma once

#include "parser.h"

typedef enum {
    PARSING_ANT_COUNT,
    PARSING_ROOMS,
    PARSING_TUNNELS
} parser_state_t;

typedef struct {
    anthill_t *anthill;
    parser_state_t state;
    char *line;
    bool will_be_start;
    bool will_be_end;
} parser_t;

/**
 * @brief Get the next line from stdin
 *
 * @param parser the parser
 */
void parser_get_next_line(parser_t *parser);

/**
 * @brief Parse the current line
 *
 * @param parser the parser
 * @return true if the line was parsed
 * @return false if the line was not parsed
 */
bool parser_process_line(parser_t *parser);

/**
 * @brief Parse the ant count
 *
 * @param parser the parser
 * @return true if the ant count was parsed
 * @return false if the ant count was not parsed
 */
bool parser_process_ant_count(parser_t *parser);

/**
 * @brief Parse a room
 *
 * @param parser the parser
 * @return true if the room was parsed
 * @return false if the room was not parsed
 */
bool parser_process_room(parser_t *parser);

/**
 * @brief Parse a tunnel
 *
 * @param parser the parser
 * @return true if the tunnel was parsed
 * @return false if the tunnel was not parsed
 */
bool parser_process_tunnel(parser_t *parser);

/**
 * @brief Check if the current line is a comment
 *
 * @param parser the parser
 * @return true if the line is a comment
 * @return false if the line is not a comment
 */
bool parser_is_comment(parser_t *parser);

/**
 * @brief Check if the current line is a command
 *
 * @param parser the parser
 * @return true if the line is a command
 * @return false if the line is not a command
 */
bool parser_is_command(parser_t *parser);

/**
 * @brief Check if the current line is a room
 *
 * @param parser the parser
 * @return true if the line is a room
 * @return false if the line is not a room
 */
bool parser_is_room(parser_t *parser);

/**
 * @brief Check if the current line is a tunnel
 *
 * @param parser the parser
 * @return true if the line is a tunnel
 * @return false if the line is not a tunnel
 */
bool parser_is_tunnel(parser_t *parser);

/**
 * @brief Print the line without the comments
 *
 * @param line the line to print
 */
void parser_print_line_cleaned(char *line);
