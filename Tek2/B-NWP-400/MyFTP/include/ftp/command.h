/*
** EPITECH PROJECT, 2024
** command.h
** File description:
** command.h
*/

#pragma once

#include <stdbool.h>

/****************************** Data structures ******************************/

/// Forward declaration of the client structure
struct client;

/// Represents a command handler
typedef bool (*command_handler_t)(struct client *client, char **args);

/// Represents a command
typedef struct {
    const char *name;
    command_handler_t handler;
} command_t;

/*****************************************************************************/

/********************************** Parsing **********************************/

/// Returns the command handler for a given command
command_handler_t command_parse(char **args);

/*****************************************************************************/

/********************************* Handlers **********************************/

/// Handles any unknown command
bool command_unknown(struct client *client, char **args);

/// Handles NOOP command
bool command_noop(struct client *client, char **args);

/// Handles USER command
bool command_user(struct client *client, char **args);

/// Handles PASS command
bool command_pass(struct client *client, char **args);

/// Handles HELP command
bool command_help(struct client *client, char **args);

/// Handles QUIT command
bool command_quit(struct client *client, char **args);

/// Handles PWD command
bool command_pwd(struct client *client, char **args);

/// Handles CDUP command
bool command_cdup(struct client *client, char **args);

/// Handles CWD command
bool command_cwd(struct client *client, char **args);

/// Handles PORT command
bool command_port(struct client *client, char **args);

/// Handles PASV command
bool command_pasv(struct client *client, char **args);

/// Handles LIST command
bool command_list(struct client *client, char **args);

/// Handles DELE command
bool command_dele(struct client *client, char **args);

/// Handles STOR command
bool command_stor(struct client *client, char **args);

/// Handles RETR command
bool command_retr(struct client *client, char **args);

/*****************************************************************************/
