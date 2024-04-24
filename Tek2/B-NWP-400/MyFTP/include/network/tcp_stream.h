/*
** EPITECH PROJECT, 2024
** tcp_stream.h
** File description:
** tcp_stream.h
*/

#pragma once

#include "socket.h"

/****************************** Data structures ******************************/

/// Represents a TCP stream
typedef socket_t tcp_stream_t;

/*****************************************************************************/

/******************************* Init & Deinit *******************************/

/// Initializes a TCP stream
bool tcp_stream_init(tcp_stream_t *self, const ipv4_address_t *address);

/// Initializes a TCP stream from a socket
void tcp_stream_init_from_socket(tcp_stream_t *self, socket_t *socket);

/// Deinitializes a TCP stream
void tcp_stream_deinit(tcp_stream_t *self);

/*****************************************************************************/

/******************************* Read & Write ********************************/

/// Reads from a TCP stream
ssize_t tcp_stream_read(tcp_stream_t *self, void *buffer, size_t size);

/// Writes to a TCP stream
ssize_t tcp_stream_write(tcp_stream_t *self, const void *buffer, size_t size);

/*****************************************************************************/
