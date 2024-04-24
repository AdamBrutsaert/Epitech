/*
** EPITECH PROJECT, 2024
** parsing.h
** File description:
** parsing.h
*/

#pragma once

#include "network/socket.h"

#include <stdbool.h>
#include <stdint.h>

/********************************** Parsing **********************************/

/// Parses a string into an array of strings removing whitespaces
char **parse_args_from_string(const char *string);

/// Parses a string into a port
bool parse_port(uint16_t *port, const char *string);

/// Removes trailing slashes from a path
char *remove_trailing_slashes(char *path);

/// Parses a string into an ip
bool parse_address(ipv4_address_t *address, const char *string);

/// Parses a path removing trailing slashes and resolving '..' and '.'
char *parse_path(const char *path);

/*****************************************************************************/

/********************************** Freeing **********************************/

void free_args_array(char **array);

/*****************************************************************************/
