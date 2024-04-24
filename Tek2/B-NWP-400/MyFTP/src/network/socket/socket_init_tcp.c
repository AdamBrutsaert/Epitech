/*
** EPITECH PROJECT, 2024
** socket_init_tcp.c
** File description:
** socket_init_tcp.c
*/

#include "network/socket.h"

bool socket_init_tcp(socket_t *self)
{
    return socket_init(
        self,
        SOCKET_DOMAIN_IPV4,
        SOCKET_TYPE_STREAM,
        SOCKET_PROTOCOL_TCP
    );
}
