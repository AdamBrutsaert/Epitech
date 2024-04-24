/*
** EPITECH PROJECT, 2024
** socket_local_address_ipv4.c
** File description:
** socket_local_address_ipv4.c
*/

#include "my/network/socket.h"

bool socket_local_address_ipv4(socket_t *self, ipv4_address_t *address)
{
    struct sockaddr_in addr;
    socklen_t len = sizeof(addr);

    if (getsockname(*self, (struct sockaddr *)&addr, &len) == -1)
        return false;
    address->port = ntohs(addr.sin_port);
    *(uint32_t *)address->address = ntohl(addr.sin_addr.s_addr);
    return true;
}
