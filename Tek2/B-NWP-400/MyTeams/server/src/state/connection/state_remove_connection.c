/*
** EPITECH PROJECT, 2024
** state_remove_connection.c
** File description:
** state_remove_connection.c
*/

#include "state.h"

void state_remove_connection(state_t *self, const stream_t *stream)
{
    connection_t *connection;

    for (size_t i = 0; i < VEC_LEN(self->connections); i++) {
        connection = *(connection_t **)VEC_AT(self->connections, i);
        if (connection->stream == stream) {
            vec_remove(self->connections, i);
            connection->user->connections -= 1;
            connection_destroy(connection);
            return;
        }
    }
}
