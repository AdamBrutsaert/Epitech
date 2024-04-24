/*
** EPITECH PROJECT, 2024
** cl_user_logged_out.c
** File description:
** cl_user_logged_out.c
*/

#include "protocol/packet/user_logged_out.h"
#include "my/memory/allocation.h"

void cl_user_logged_out_packet_encode(
    cl_user_logged_out_packet_t *self,
    packet_t *packet
)
{
    packet_push_u8(packet, self->type);
}

bool cl_user_logged_out_packet_decode(
    cl_user_logged_out_packet_t *self,
    packet_t *packet
)
{
    return packet_pop_u8(packet, &self->type);
}

void cl_user_logged_out_packet_destroy(cl_user_logged_out_packet_t *self)
{
    deallocate(self);
}
