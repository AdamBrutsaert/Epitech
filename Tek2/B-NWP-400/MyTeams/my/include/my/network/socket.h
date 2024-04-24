/*
** EPITECH PROJECT, 2024
** socket.h
** File description:
** socket.h
*/

#pragma once

#include <stdint.h>
#include <netinet/in.h>

/*********************************** Types ***********************************/

/// Represents a socket
typedef int socket_t;

/// Represents a socket domain
typedef enum {
    SOCKET_DOMAIN_IPV4 = AF_INET,
} socket_domain_t;

/// Represents a socket type
typedef enum {
    SOCKET_TYPE_STREAM = SOCK_STREAM,
} socket_type_t;

/// Represents a socket protocol
typedef enum {
    SOCKET_PROTOCOL_TCP = IPPROTO_TCP,
} socket_protocol_t;

/// Represents an IPv4 address
typedef struct {
    uint8_t address[4];
    uint16_t port;
} ipv4_address_t;

/*****************************************************************************/

/******************************* Init & Deinit *******************************/

/// Creates a socket
socket_t *socket_create(void);

/// Deinitializes a socket
void socket_destroy(socket_t *self);

/*****************************************************************************/

/****************************** Open and Close *******************************/

/// Opens a socket
bool socket_open(
    socket_t *self,
    socket_domain_t domain,
    socket_type_t type,
    socket_protocol_t protocol
);

/// Opens a IPv4/TCP socket
bool socket_open_ipv4_tcp(socket_t *self);

/// Closes a socket
void socket_close(socket_t *self);

/// Checks if a socket is opened
#define SOCKET_OPENED(self) (*self > 0)

/*****************************************************************************/

/******************************** Connection *********************************/

/// Connects a socket to an IPv4 address
bool socket_connect_ipv4(socket_t *self, const ipv4_address_t *address);

/// Binds a socket to an IPv4 address
bool socket_bind_ipv4(socket_t *self, const ipv4_address_t *address);

/// Listens for incoming connections on a socket
bool socket_listen(socket_t *self, uint32_t backlog);

/// Accepts an IPv4 incoming connection on a socket
bool socket_accept_ipv4(
    socket_t *self,
    socket_t **client,
    ipv4_address_t *address
);

/// Retrieves the local IPv4 address of a socket
bool socket_local_address_ipv4(socket_t *self, ipv4_address_t *address);

/*****************************************************************************/

/**************************** Reading and Writing ****************************/

/// Reads data from a socket
ssize_t socket_read(socket_t *self, void *buffer, size_t length);

/// Writes data to a socket
ssize_t socket_write(socket_t *self, const void *buffer, size_t length);

/*****************************************************************************/
