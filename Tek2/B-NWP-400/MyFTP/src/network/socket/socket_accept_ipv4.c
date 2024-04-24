/*
** EPITECH PROJECT, 2024
** socket_accept.c
** File description:
** socket_accept.c
*/

#include "network/socket.h"

bool socket_accept_ipv4(
    socket_t *self,
    socket_t *client,
    ipv4_address_t *address
)
{
    struct sockaddr_in addr;
    socklen_t addr_len = sizeof(addr);

    *client = accept(*self, (struct sockaddr *)&addr, &addr_len);
    if (*client == -1)
        return false;
    address->address = ntohl(addr.sin_addr.s_addr);
    address->port = ntohs(addr.sin_port);
    return true;
}
