/*
** EPITECH PROJECT, 2024
** socket_close.c
** File description:
** socket_close.c
*/

#include "my/network/socket.h"

#include <unistd.h>

void socket_close(socket_t *self)
{
    if (SOCKET_OPENED(self))
        close(*self);
    *self = -1;
}
