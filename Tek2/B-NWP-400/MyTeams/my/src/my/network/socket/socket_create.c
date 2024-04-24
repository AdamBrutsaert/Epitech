/*
** EPITECH PROJECT, 2024
** socket_create.c
** File description:
** socket_create.c
*/

#include "my/network/socket.h"
#include "my/memory/allocation.h"

socket_t *socket_create(void)
{
    socket_t *self = allocate(sizeof(socket_t));

    *self = -1;
    return self;
}
