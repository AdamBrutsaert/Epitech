/*
** EPITECH PROJECT, 2024
** socket_selector_add_write.c
** File description:
** socket_selector_add_write.c
*/

#include "network/socket_selector.h"

bool socket_selector_add_write(
    socket_selector_t *self,
    const socket_t *socket
)
{
    if (*socket < 0 || *socket >= SOCKET_SELECTOR_MAX_FD)
        return false;
    FD_SET(*socket, &self->write_fds);
    if (*socket > self->max_fd)
        self->max_fd = *socket;
    return true;
}
