/*
** EPITECH PROJECT, 2024
** client_handle_user_logged_in.c
** File description:
** client_handle_user_logged_in.c
*/

#include "client.h"

#include "myteams/logging_server.h"

static user_t *get_user_or_error(
    client_t *self,
    cl_send_private_message_packet_t *packet
)
{
    sv_error_unknown_user_packet_t error;
    user_t *user = state_get_user_by_uuid(self->state, packet->to_uuid);

    if (user == nullptr) {
        error.type = PACKET_TYPE_SV_ERROR_UNKNOWN_USER;
        error.uuid = packet->to_uuid;
        stream_send_packet(self->stream, (cl_sv_packet_t *)&error);
        return nullptr;
    }
    return user;
}

static void create_and_send_msg(
    client_t *self,
    cl_send_private_message_packet_t *packet,
    user_t *user
)
{
    sv_send_private_message_packet_t response;
    message_t *message;

    message = message_create(self->user->uuid, user->uuid, packet->message,
        time(NULL));
    state_add_message(self->state, message);
    response.type = PACKET_TYPE_SV_SEND_PRIVATE_MESSAGE;
    response.from_uuid = self->user->uuid;
    response.message = packet->message;
    state_send_packet_to_user(self->state, user, (cl_sv_packet_t *)&response);
    server_event_private_message_sended(STRING_CDATA(self->user->uuid),
        STRING_CDATA(packet->to_uuid), STRING_CDATA(packet->message));
}

void client_handle_send_private_message(
    client_t *self,
    cl_send_private_message_packet_t *packet
)
{
    user_t *user = get_user_or_error(self, packet);

    if (user != nullptr)
        create_and_send_msg(self, packet, user);
}
