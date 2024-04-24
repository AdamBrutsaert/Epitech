/*
** EPITECH PROJECT, 2024
** socket_open.c
** File description:
** socket_open.c
*/

#include "my/network/socket.h"

bool socket_open(
    socket_t *self,
    socket_domain_t domain,
    socket_type_t type,
    socket_protocol_t protocol
)
{
    *self = socket(domain, type, protocol);
    return SOCKET_OPENED(self);
}
