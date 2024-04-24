/*
** EPITECH PROJECT, 2024
** selector_create.c
** File description:
** selector_create.c
*/

#include "my/network/selector.h"
#include "my/memory/allocation.h"

selector_t *selector_create(void)
{
    selector_t *self = allocate(sizeof(selector_t));

    self->max_fd = 0;
    FD_ZERO(&self->read_fds);
    FD_ZERO(&self->write_fds);
    FD_ZERO(&self->read_ready_fds);
    FD_ZERO(&self->write_ready_fds);
    return self;
}
