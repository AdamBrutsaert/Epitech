/*
** EPITECH PROJECT, 2024
** client_handle_get_all_users.c
** File description:
** client_handle_get_all_users.c
*/

#include "client.h"

void client_handle_get_all_users(
    client_t *self,
    __attribute__((unused)) cl_get_all_users_packet_t *packet
)
{
    sv_get_all_users_packet_t response = {
        .type = PACKET_TYPE_SV_GET_ALL_USERS,
        .users = self->state->users
    };

    stream_send_packet(self->stream, (cl_sv_packet_t *)&response);
}
