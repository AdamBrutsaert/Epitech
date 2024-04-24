/*
** EPITECH PROJECT, 2024
** socket_write.c
** File description:
** socket_write.c
*/

#include "my/network/socket.h"

#include <unistd.h>

ssize_t socket_write(socket_t *self, const void *buffer, size_t length)
{
    return write(*self, buffer, length);
}
