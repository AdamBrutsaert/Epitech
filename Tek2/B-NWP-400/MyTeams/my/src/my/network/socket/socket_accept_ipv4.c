/*
** EPITECH PROJECT, 2024
** socket_accept_ipv4.c
** File description:
** socket_accept_ipv4.c
*/

#include "my/network/socket.h"

bool socket_accept_ipv4(
    socket_t *self,
    socket_t **client,
    ipv4_address_t *address
)
{
    struct sockaddr_in addr;
    socklen_t addr_len = sizeof(addr);
    socket_t tmp = accept(*self, (struct sockaddr *)&addr, &addr_len);

    if (tmp == -1)
        return false;
    *client = socket_create();
    **client = tmp;
    *(uint32_t *)address->address = ntohl(addr.sin_addr.s_addr);
    address->port = ntohs(addr.sin_port);
    return true;
}
