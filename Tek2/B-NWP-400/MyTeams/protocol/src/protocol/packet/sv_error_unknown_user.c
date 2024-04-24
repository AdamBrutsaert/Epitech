/*
** EPITECH PROJECT, 2024
** sv_error_unknown_user.c
** File description:
** sv_error_unknown_user.c
*/

#include "protocol/packet/error_unknown_user.h"
#include "my/memory/allocation.h"

void sv_error_unknown_user_packet_encode(
    sv_error_unknown_user_packet_t *self,
    packet_t *packet
)
{
    packet_push_u8(packet, self->type);
    packet_push_string(packet, self->uuid);
}

bool sv_error_unknown_user_packet_decode(
    sv_error_unknown_user_packet_t *self,
    packet_t *packet
)
{
    return packet_pop_string(packet, &self->uuid)
        && packet_pop_u8(packet, &self->type);
}

void sv_error_unknown_user_packet_destroy(
    sv_error_unknown_user_packet_t *self
)
{
    string_destroy(self->uuid);
    deallocate(self);
}
