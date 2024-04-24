/*
** EPITECH PROJECT, 2024
** socket_get_local_address_ipv4.c
** File description:
** socket_get_local_address_ipv4.c
*/

#include "network/socket.h"

bool socket_get_local_address_ipv4(socket_t *self, ipv4_address_t *address)
{
    struct sockaddr_in addr;
    socklen_t len = sizeof(addr);

    if (getsockname(*self, (struct sockaddr *)&addr, &len) == -1)
        return false;
    address->port = ntohs(addr.sin_port);
    address->address = ntohl(addr.sin_addr.s_addr);
    return true;
}
