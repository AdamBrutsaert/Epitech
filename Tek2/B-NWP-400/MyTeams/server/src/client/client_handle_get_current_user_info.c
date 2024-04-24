/*
** EPITECH PROJECT, 2024
** client_handle_get_current_user_info.c
** File description:
** client_handle_get_current_user_info.c
*/

#include "client.h"

void client_handle_get_current_user_info(
    client_t *self,
    __attribute__((unused)) cl_get_current_user_info_packet_t *packet
)
{
    sv_get_current_user_info_packet_t res;

    res.type = PACKET_TYPE_SV_GET_CURRENT_USER_INFO;
    res.user = self->user;
    stream_send_packet(self->stream, (cl_sv_packet_t *)&res);
}
