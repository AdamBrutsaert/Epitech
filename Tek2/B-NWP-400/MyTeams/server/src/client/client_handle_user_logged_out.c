/*
** EPITECH PROJECT, 2024
** client_handle_user_logged_out.c
** File description:
** client_handle_user_logged_out.c
*/

#include "client.h"
#include "myteams/logging_server.h"

void client_handle_user_logged_out(
    client_t *self,
    __attribute__((unused)) cl_user_logged_out_packet_t *packet
)
{
    sv_disconnection_success_packet_t res;

    res.type = PACKET_TYPE_SV_DISCONNECTION_SUCCESS;
    stream_send_packet(self->stream, (cl_sv_packet_t *)&res);
    state_broadcast_users_logout(self->state, self->user);
    state_remove_connection(self->state, self->stream);
    server_event_user_logged_out(STRING_CDATA(self->user->uuid));
    self->user = nullptr;
}
