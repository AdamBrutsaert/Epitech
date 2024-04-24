/*
** EPITECH PROJECT, 2024
** selector_wait.c
** File description:
** selector_wait.c
*/

#include "my/network/selector.h"

#include <stddef.h>

bool selector_wait(selector_t *self, uint64_t timeout_us)
{
    struct timeval timeout = {
        .tv_sec = timeout_us / 1000000,
        .tv_usec = timeout_us % 1000000
    };
    struct timeval *ptr_timeout = timeout_us == 0 ? NULL : &timeout;
    int max_fd = self->max_fd;

    self->read_ready_fds = self->read_fds;
    self->write_ready_fds = self->write_fds;
    self->max_fd = 0;
    FD_ZERO(&self->read_fds);
    FD_ZERO(&self->write_fds);
    return select(max_fd + 1, &self->read_ready_fds, &self->write_ready_fds,
        NULL, ptr_timeout) >= 0;
}
