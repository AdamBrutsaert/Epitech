/*
** EPITECH PROJECT, 2024
** socket_open_ipv4_tcp.c
** File description:
** socket_open_ipv4_tcp.c
*/

#include "my/network/socket.h"

bool socket_open_ipv4_tcp(socket_t *self)
{
    return socket_open(
        self,
        SOCKET_DOMAIN_IPV4,
        SOCKET_TYPE_STREAM,
        SOCKET_PROTOCOL_TCP
    );
}
