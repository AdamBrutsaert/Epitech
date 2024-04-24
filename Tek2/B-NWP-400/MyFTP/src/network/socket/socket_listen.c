/*
** EPITECH PROJECT, 2024
** socket_listen.c
** File description:
** socket_listen.c
*/

#include "network/socket.h"

bool socket_listen(socket_t *self, int backlog)
{
    return listen(*self, backlog) != -1;
}
