/*
** EPITECH PROJECT, 2024
** server_destroy.c
** File description:
** server_destroy.c
*/

#include "server.h"
#include "client.h"

#include "my/memory/allocation.h"

void server_destroy(server_t *self)
{
    state_save(self->state);
    for (size_t i = 0; i < VEC_LEN(self->clients); i++)
        client_destroy(*(client_t **)VEC_AT(self->clients, i));
    vec_destroy(self->clients);
    state_destroy(self->state);
    selector_destroy(self->selector);
    socket_destroy(self->socket);
    deallocate(self);
}
