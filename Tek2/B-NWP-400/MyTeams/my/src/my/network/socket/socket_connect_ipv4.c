/*
** EPITECH PROJECT, 2024
** socket_connect_ipv4.c
** File description:
** socket_connect_ipv4.c
*/

#include "my/network/socket.h"

bool socket_connect_ipv4(socket_t *self, const ipv4_address_t *address)
{
    struct sockaddr_in addr;

    addr.sin_addr.s_addr = htonl(*(uint32_t *)address->address);
    addr.sin_port = htons(address->port);
    addr.sin_family = AF_INET;
    return connect(*self, (struct sockaddr *)&addr, sizeof(addr)) != -1;
}
