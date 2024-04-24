/*
** EPITECH PROJECT, 2024
** tcp_listener_accept.c
** File description:
** tcp_listener_accept.c
*/

#include "network/tcp_listener.h"

bool tcp_listener_accept(
    tcp_listener_t *self,
    tcp_stream_t *peer,
    ipv4_address_t *address
)
{
    socket_t peer_socket;

    if (!socket_accept_ipv4(self, &peer_socket, address))
        return false;
    tcp_stream_init_from_socket(peer, &peer_socket);
    return true;
}
