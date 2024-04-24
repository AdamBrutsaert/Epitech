/*
** EPITECH PROJECT, 2024
** sv_get_current_user_info.c
** File description:
** sv_get_current_user_info.c
*/

#include "protocol/packet/get_current_user_info.h"
#include "my/memory/allocation.h"

void sv_get_current_user_info_packet_encode(
    sv_get_current_user_info_packet_t *self,
    packet_t *packet
)
{
    packet_push_u8(packet, self->type);
    packet_push_user(packet, self->user);
}

bool sv_get_current_user_info_packet_decode(
    sv_get_current_user_info_packet_t *self,
    packet_t *packet
)
{
    return packet_pop_user(packet, &self->user)
        && packet_pop_u8(packet, &self->type);
}

void sv_get_current_user_info_packet_destroy(
    sv_get_current_user_info_packet_t *self
)
{
    user_destroy(self->user);
    deallocate(self);
}
