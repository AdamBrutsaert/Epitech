/*
** EPITECH PROJECT, 2024
** stream_send_packet.c
** File description:
** stream_send_packet.c
*/

#include "protocol/stream.h"

void stream_send_packet(stream_t *self, cl_sv_packet_t *packet)
{
    packet_t *raw = packet_create();
    uint32_t length;

    packet_push_cl_sv_packet(raw, packet);
    length = htonl(PACKET_LEN(raw));
    vec_push_back_some(self->write_buffer, &length, 4);
    vec_push_back_some(self->write_buffer, PACKET_DATA(raw), PACKET_LEN(raw));
    packet_destroy(raw);
}
