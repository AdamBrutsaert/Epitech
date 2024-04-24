/*
** EPITECH PROJECT, 2024
** socket_selector_add_read.c
** File description:
** socket_selector_add_read.c
*/

#include "network/socket_selector.h"

bool socket_selector_add_read(socket_selector_t *self, const socket_t *socket)
{
    if (*socket < 0 || *socket >= SOCKET_SELECTOR_MAX_FD)
        return false;
    FD_SET(*socket, &self->read_fds);
    if (*socket > self->max_fd)
        self->max_fd = *socket;
    return true;
}
