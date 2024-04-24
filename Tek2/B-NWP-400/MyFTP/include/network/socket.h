/*
** EPITECH PROJECT, 2024
** socket.h
** File description:
** socket.h
*/

#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <netinet/in.h>

#define SOCKET_DOMAIN_IPV4 AF_INET
#define SOCKET_TYPE_STREAM SOCK_STREAM
#define SOCKET_PROTOCOL_TCP IPPROTO_TCP

/****************************** Data structures ******************************/

/// Represents a socket
typedef int socket_t;

/// Represents an IPv4 address
typedef struct {
    uint32_t address;
    uint16_t port;
} ipv4_address_t;

/*****************************************************************************/

/******************************* Init & Deinit *******************************/

/// Initializes a socket
bool socket_init(socket_t *self, int domain, int type, int protocol);

/// Initializes a TCP socket
bool socket_init_tcp(socket_t *self);

/// Deinitializes a socket
void socket_deinit(socket_t *self);

/*****************************************************************************/

/******************************** Connection *********************************/

/// Connects a socket to an address
bool socket_connect_ipv4(socket_t *self, const ipv4_address_t *address);

/// Binds a socket to an address
bool socket_bind_ipv4(socket_t *self, const ipv4_address_t *address);

/// Listens for incoming connections on a socket
bool socket_listen(socket_t *self, int backlog);

/// Accepts an incoming connection on a socket
bool socket_accept_ipv4(
    socket_t *self,
    socket_t *client,
    ipv4_address_t *address
);

/// Retrieves the local address of a socket
bool socket_get_local_address_ipv4(socket_t *self, ipv4_address_t *address);

/*****************************************************************************/
