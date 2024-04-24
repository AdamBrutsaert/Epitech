/*
** EPITECH PROJECT, 2024
** server_run.c
** File description:
** server_run.c
*/

#include "ftp/server.h"

bool server_run(server_t *self)
{
    while (true) {
        if (!server_register(self))
            return false;
        if (!socket_selector_wait(&self->selector, 1000000))
            return false;
        if (socket_selector_can_read(&self->selector, &self->listener)
            && !server_accept(self))
            return false;
        server_update(self);
        server_remove_errored(self);
    }
    return true;
}
