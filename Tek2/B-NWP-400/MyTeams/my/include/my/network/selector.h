/*
** EPITECH PROJECT, 2024
** selector.h
** File description:
** selector.h
*/

#pragma once

#include "socket.h"

#include <sys/select.h>

#define SELECTOR_MAX_FD FD_SETSIZE
#define SELECTOR_CAN_REGISTER(socket) ((*socket) < SELECTOR_MAX_FD)

/****************************** Data structures ******************************/

/// Represents a selector
typedef struct {
    int max_fd;
    fd_set read_fds;
    fd_set read_ready_fds;
    fd_set write_fds;
    fd_set write_ready_fds;
} selector_t;

/*****************************************************************************/

/******************************* Init & Deinit *******************************/

/// Creates the socket selector
selector_t *selector_create(void);

/// Destroys the socket selector
void selector_destroy(selector_t *self);

/*****************************************************************************/

/******************************** Registering ********************************/

/// Adds a socket to the selector for reading
bool selector_add_read(selector_t *self, const socket_t *socket);

/// Adds a socket to the selector for writing
bool selector_add_write(selector_t *self, const socket_t *socket);

/*****************************************************************************/

/********************************* Checking **********************************/

/// Checks if a socket is ready for reading
bool selector_can_read(const selector_t *self, const socket_t *socket);

/// Checks if a socket is ready for writing
bool selector_can_write(const selector_t *self, const socket_t *socket);

/*****************************************************************************/

/********************************* Waiting ***********************************/

/// Waits for a socket to be ready for reading or writing
bool selector_wait(selector_t *self, uint64_t timeout_us);

/*****************************************************************************/
