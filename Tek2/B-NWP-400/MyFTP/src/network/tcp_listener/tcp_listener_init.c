/*
** EPITECH PROJECT, 2024
** tcp_listener_init.c
** File description:
** tcp_listener_init.c
*/

#include "network/tcp_listener.h"

bool tcp_listener_init(tcp_listener_t *self, const ipv4_address_t *address)
{
    if (!socket_init_tcp(self))
        return false;
    if (!socket_bind_ipv4(self, address) || !socket_listen(self, 10)) {
        socket_deinit(self);
        return false;
    }
    return true;
}
