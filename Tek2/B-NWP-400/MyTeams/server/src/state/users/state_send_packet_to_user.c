/*
** EPITECH PROJECT, 2024
** state_send_packet_to_user.c
** File description:
** state_send_packet_to_user.c
*/

#include "state.h"

void state_send_packet_to_user(
    state_t *self,
    user_t *user,
    cl_sv_packet_t *packet
)
{
    connection_t *connection;

    for (size_t i = 0; i < VEC_LEN(self->connections); i++) {
        connection = *(connection_t **)VEC_AT(self->connections, i);
        if (connection->user == user)
            stream_send_packet(connection->stream, packet);
    }
}
