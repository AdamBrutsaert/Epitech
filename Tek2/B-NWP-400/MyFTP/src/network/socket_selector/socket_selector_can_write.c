/*
** EPITECH PROJECT, 2024
** socket_selector_can_write.c
** File description:
** socket_selector_can_write.c
*/

#include "network/socket_selector.h"

bool socket_selector_can_write(
    const socket_selector_t *self,
    const socket_t *socket
)
{
    if (*socket < 0 || *socket >= SOCKET_SELECTOR_MAX_FD)
        return false;
    return FD_ISSET(*socket, &self->write_ready_fds);
}
