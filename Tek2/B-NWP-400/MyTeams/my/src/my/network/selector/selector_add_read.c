/*
** EPITECH PROJECT, 2024
** selector_add_read.c
** File description:
** selector_add_read.c
*/

#include "my/network/selector.h"

bool selector_add_read(selector_t *self, const socket_t *socket)
{
    if (*socket >= SELECTOR_MAX_FD)
        return false;
    FD_SET(*socket, &self->read_fds);
    if (*socket > self->max_fd)
        self->max_fd = *socket;
    return true;
}
