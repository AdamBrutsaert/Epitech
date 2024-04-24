/*
** EPITECH PROJECT, 2024
** cl_get_current_user_info.c
** File description:
** cl_get_current_user_info.c
*/

#include "protocol/packet/get_current_user_info.h"
#include "my/memory/allocation.h"

void cl_get_current_user_info_packet_encode(
    cl_get_current_user_info_packet_t *self,
    packet_t *packet
)
{
    packet_push_u8(packet, self->type);
}

bool cl_get_current_user_info_packet_decode(
    cl_get_current_user_info_packet_t *self,
    packet_t *packet
)
{
    return packet_pop_u8(packet, &self->type);
}

void cl_get_current_user_info_packet_destroy(
    cl_get_current_user_info_packet_t *self
)
{
    deallocate(self);
}
