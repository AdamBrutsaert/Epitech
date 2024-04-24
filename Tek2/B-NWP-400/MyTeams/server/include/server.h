/*
** EPITECH PROJECT, 2024
** server.h
** File description:
** server.h
*/

#pragma once

#include "state.h"

#include "my/network/selector.h"

/*********************************** Types ***********************************/

/// Represents a server
typedef struct {
    socket_t *socket;
    selector_t *selector;
    vec_t *clients;
    state_t *state;
} server_t;

/*****************************************************************************/

/******************************* Init & Deinit *******************************/

/// Creates a server
server_t *server_create(void);

/// Destroys a server
void server_destroy(server_t *self);

/*****************************************************************************/

/************************************ Run ************************************/

/// Runs the server from args
int server_run_from_args(int ac, char **av);

/// Runs the server
bool server_run(server_t *self, const ipv4_address_t *address);

/*****************************************************************************/
