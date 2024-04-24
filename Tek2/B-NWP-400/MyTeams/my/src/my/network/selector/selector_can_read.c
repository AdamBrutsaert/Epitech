/*
** EPITECH PROJECT, 2024
** selector_can_read.c
** File description:
** selector_can_read.c
*/

#include "my/network/selector.h"

bool selector_can_read(const selector_t *self, const socket_t *socket)
{
    if (*socket >= SELECTOR_MAX_FD)
        return false;
    return FD_ISSET(*socket, &self->read_ready_fds);
}
