/*
** EPITECH PROJECT, 2024
** cl_get_all_users.h
** File description:
** cl_get_all_users.h
*/

#include "protocol/packet/get_all_users.h"
#include "my/memory/allocation.h"

void cl_get_all_users_packet_encode(
    cl_get_all_users_packet_t *self,
    packet_t *packet
)
{
    packet_push_u8(packet, self->type);
}

bool cl_get_all_users_packet_decode(
    cl_get_all_users_packet_t *self,
    packet_t *packet
)
{
    return packet_pop_u8(packet, &self->type);
}

void cl_get_all_users_packet_destroy(cl_get_all_users_packet_t *self)
{
    deallocate(self);
}
