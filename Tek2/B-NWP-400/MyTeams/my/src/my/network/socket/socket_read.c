/*
** EPITECH PROJECT, 2024
** socket_read.c
** File description:
** socket_read.c
*/

#include "my/network/socket.h"

#include <unistd.h>

ssize_t socket_read(socket_t *self, void *buffer, size_t length)
{
    return read(*self, buffer, length);
}
