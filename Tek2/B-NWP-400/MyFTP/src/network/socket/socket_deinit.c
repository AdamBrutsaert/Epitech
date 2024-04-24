/*
** EPITECH PROJECT, 2024
** socket_deinit.c
** File description:
** socket_deinit.c
*/

#include "network/socket.h"

#include <unistd.h>

void socket_deinit(socket_t *self)
{
    close(*self);
}
