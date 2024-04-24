/*
** EPITECH PROJECT, 2024
** client.h
** File description:
** client.h
*/

#pragma once

#include "control.h"
#include "data.h"
#include "user.h"
#include "path.h"
#include "command.h"

#include <sys/types.h>

/****************************** Data structures ******************************/

/// Represents an FTP client state
typedef enum {
    CLIENT_HANDLING_COMMAND = 0,
    CLIENT_WAITING_DATA_CONNECTION,
    CLIENT_WAITING_CHILD_PROCESS,
} client_state_t;

/// Represents an FTP client
typedef struct client {
    client_state_t state;
    control_t control;
    data_t data;
    path_t path;
    user_t user;
    command_handler_t command;
    char **command_args;
    pid_t pid;
    pid_t child_status;
    bool error;
    bool quit;
} client_t;

/*****************************************************************************/

/******************************* Init & Deinit *******************************/

/// Initializes the client
bool client_init(
    client_t *self,
    tcp_stream_t *stream,
    const ipv4_address_t *address,
    const path_t *path
);

/// Deinitializes the client
void client_deinit(client_t *self);

/*****************************************************************************/

/********************************** Getters **********************************/

/// Returns the control of the client
control_t *client_control(client_t *self);

/// Returns the data of the client
data_t *client_data(client_t *self);

/// Returns the user of the client
user_t *client_user(client_t *self);

/// Returns the path of the client
path_t *client_path(client_t *self);

/// Returns the PID of the forked process of the client
pid_t client_pid(const client_t *self);

/// Returns the child process status
pid_t client_child_status(const client_t *self);

/// Returns the state of the client
client_state_t client_state(const client_t *self);

/// Returns whether the client has an error
bool client_error(const client_t *self);

/*****************************************************************************/

/********************************** Setters **********************************/

/// Marks the client as wanting to quit
void client_quit(client_t *self);

/// Sets the PID of the forked process of the client
void client_set_pid(client_t *self, pid_t pid);

/// Sets the state of the client
void client_set_state(client_t *self, client_state_t state);

/*****************************************************************************/

/********************************** Update ***********************************/

/// Registers clients to the socket selector
void client_register(client_t *self, socket_selector_t *selector);

/// Updates the client
void client_update(client_t *self, socket_selector_t *selector);

/*****************************************************************************/
