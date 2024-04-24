/*
** EPITECH PROJECT, 2024
** socket_init.c
** File description:
** socket_init.c
*/

#include "network/socket.h"

bool socket_init(socket_t *self, int domain, int type, int protocol)
{
    *self = socket(domain, type, protocol);
    return *self != -1;
}
