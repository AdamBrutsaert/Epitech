/*
** EPITECH PROJECT, 2024
** server.h
** File description:
** server.h
*/

#pragma once

#include "client.h"
#include "network/tcp_listener.h"

/****************************** Data structures ******************************/

/// Represents an FTP server
typedef struct {
    path_t path;
    tcp_listener_t listener;
    socket_selector_t selector;
    vec_t clients;
} server_t;

/*****************************************************************************/

/******************************* Init & Deinit *******************************/

/// Initializes the server
bool server_init(server_t *self, const ipv4_address_t *address, path_t *path);

/// Deinitializes the server
void server_deinit(server_t *self);

/*****************************************************************************/

/************************************ Run ************************************/

/// Runs the server
bool server_run(server_t *self);

/// Runs the server from arguments
int server_run_from_args(int argc, char **argv);

/*****************************************************************************/

/********************************* Run Loop **********************************/

/// Register all the file descriptors to the selector
bool server_register(server_t *self);

/// Accepts a new client
bool server_accept(server_t *self);

/// Removes errored clients
void server_remove_errored(server_t *self);

/// Update all clients
void server_update(server_t *self);

/*****************************************************************************/
