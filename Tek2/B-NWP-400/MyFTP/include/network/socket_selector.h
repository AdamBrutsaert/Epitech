/*
** EPITECH PROJECT, 2024
** selector.h
** File description:
** selector.h
*/

#pragma once

#include "socket.h"

#include <sys/select.h>

#define SOCKET_SELECTOR_MAX_FD FD_SETSIZE
#define SOCKET_SELECTOR_CAN_REGISTER(fd) ((fd) < SOCKET_SELECTOR_MAX_FD)

/****************************** Data structures ******************************/

/// Represents a socket selector
typedef struct {
    int max_fd;
    fd_set read_fds;
    fd_set read_ready_fds;
    fd_set write_fds;
    fd_set write_ready_fds;
} socket_selector_t;

/*****************************************************************************/

/******************************* Init & Deinit *******************************/

/// Initializes the socket selector
void socket_selector_init(socket_selector_t *self);

/*****************************************************************************/

/******************************** Registering ********************************/

/// Adds a socket to the selector for reading
bool socket_selector_add_read(socket_selector_t *self, const socket_t *socket);

/// Adds a socket to the selector for writing
bool socket_selector_add_write(
    socket_selector_t *self,
    const socket_t *socket
);

/*****************************************************************************/

/********************************* Checking **********************************/

/// Checks if a socket is ready for reading
bool socket_selector_can_read(
    const socket_selector_t *self,
    const socket_t *socket
);

/// Checks if a socket is ready for writing
bool socket_selector_can_write(
    const socket_selector_t *self,
    const socket_t *socket
);

/*****************************************************************************/

/********************************* Waiting ***********************************/

/// Waits for a socket to be ready for reading or writing
bool socket_selector_wait(socket_selector_t *self, uint64_t timeout_us);

/*****************************************************************************/
