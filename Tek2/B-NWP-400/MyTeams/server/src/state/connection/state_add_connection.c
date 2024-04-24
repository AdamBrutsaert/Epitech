/*
** EPITECH PROJECT, 2024
** state_add_connection.c
** File description:
** state_add_connection.c
*/

#include "state.h"

void state_add_connection(state_t *self, stream_t *stream, user_t *user)
{
    connection_t *connection = connection_create(stream, user);

    vec_push_back(self->connections, &connection);
    user->connections += 1;
}
