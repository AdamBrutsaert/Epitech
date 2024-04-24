/*
** EPITECH PROJECT, 2024
** tcp_stream_init.c
** File description:
** tcp_stream_init.c
*/

#include "network/tcp_stream.h"

bool tcp_stream_init(tcp_stream_t *self, const ipv4_address_t *address)
{
    if (!socket_init_tcp(self))
        return false;
    if (!socket_connect_ipv4(self, address)) {
        socket_deinit(self);
        return false;
    }
    return true;
}
