/*
** EPITECH PROJECT, 2024
** client_handle_get_user.c
** File description:
** client_handle_get_user.c
*/

#include "client.h"

void client_handle_get_user(
    client_t *self,
    cl_get_user_packet_t *packet
)
{
    user_t *user;
    sv_get_user_packet_t response;
    sv_error_unknown_user_packet_t error;

    user = state_get_user_by_uuid(self->state, packet->uuid);
    if (user == nullptr) {
        error.type = PACKET_TYPE_SV_ERROR_UNKNOWN_USER;
        error.uuid = packet->uuid;
        stream_send_packet(self->stream, (cl_sv_packet_t *)&error);
        return;
    }
    response.type = PACKET_TYPE_SV_GET_USER;
    response.user = user;
    stream_send_packet(self->stream, (cl_sv_packet_t *)&response);
}
