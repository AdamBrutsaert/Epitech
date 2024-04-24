/*
** EPITECH PROJECT, 2024
** sv_user_logged_out.c
** File description:
** sv_user_logged_out.c
*/

#include "protocol/packet/user_logged_out.h"
#include "my/memory/allocation.h"

void sv_user_logged_out_packet_encode(
    sv_user_logged_out_packet_t *self,
    packet_t *packet
)
{
    packet_push_u8(packet, self->type);
    packet_push_string(packet, self->name);
    packet_push_string(packet, self->uuid);
}

bool sv_user_logged_out_packet_decode(
    sv_user_logged_out_packet_t *self,
    packet_t *packet
)
{
    return packet_pop_string(packet, &self->uuid)
        && packet_pop_string(packet, &self->name)
        && packet_pop_u8(packet, &self->type);
}

void sv_user_logged_out_packet_destroy(sv_user_logged_out_packet_t *self)
{
    string_destroy(self->name);
    string_destroy(self->uuid);
    deallocate(self);
}
