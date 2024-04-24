/*
** EPITECH PROJECT, 2024
** client_handle_get_all_private_messages.c
** File description:
** client_handle_get_all_private_messages.c
*/

#include "client.h"

void client_handle_get_all_private_messages(
    client_t *self,
    cl_get_all_private_messages_packet_t *packet
)
{
    user_t *user = state_get_user_by_uuid(self->state, packet->uuid);
    sv_error_unknown_user_packet_t error;
    sv_get_all_private_messages_packet_t res;

    if (user == nullptr) {
        error.type = PACKET_TYPE_SV_ERROR_UNKNOWN_USER;
        error.uuid = packet->uuid;
        stream_send_packet(self->stream, (cl_sv_packet_t *)&error);
        return;
    }
    res.type = PACKET_TYPE_SV_GET_ALL_PRIVATE_MESSAGES;
    res.messages = state_get_messages_between(self->state, self->user, user);
    stream_send_packet(self->stream, (cl_sv_packet_t *)&res);
    vec_destroy(res.messages);
}
