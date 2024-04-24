/*
** EPITECH PROJECT, 2024
** socket_destroy.c
** File description:
** socket_destroy.c
*/

#include "my/network/socket.h"
#include "my/memory/allocation.h"

void socket_destroy(socket_t *self)
{
    socket_close(self);
    deallocate(self);
}
