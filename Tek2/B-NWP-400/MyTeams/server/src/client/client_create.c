/*
** EPITECH PROJECT, 2024
** client_create.c
** File description:
** client_create.c
*/

#include "client.h"

#include "my/memory/allocation.h"

client_t *client_create(socket_t *socket, state_t *state)
{
    client_t *self = allocate(sizeof(client_t));

    self->stream = stream_create(socket);
    self->state = state;
    self->user = nullptr;
    return self;
}
