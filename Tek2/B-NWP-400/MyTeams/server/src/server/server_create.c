/*
** EPITECH PROJECT, 2024
** server_create.c
** File description:
** server_create.c
*/

#include "server.h"
#include "client.h"

#include "my/memory/allocation.h"

server_t *server_create(void)
{
    server_t *self = allocate(sizeof(server_t));

    self->socket = socket_create();
    self->selector = selector_create();
    self->clients = vec_create(sizeof(client_t *));
    self->state = state_create();
    state_restore(self->state);
    return self;
}
