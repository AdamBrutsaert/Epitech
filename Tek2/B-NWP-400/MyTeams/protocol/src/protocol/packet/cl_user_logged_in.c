/*
** EPITECH PROJECT, 2024
** cl_user_logged_in.c
** File description:
** cl_user_logged_in.c
*/

#include "protocol/packet/user_logged_in.h"
#include "my/memory/allocation.h"

void cl_user_logged_in_packet_encode(
    cl_user_logged_in_packet_t *self,
    packet_t *packet
)
{
    packet_push_u8(packet, self->type);
    packet_push_string(packet, self->name);
}

bool cl_user_logged_in_packet_decode(
    cl_user_logged_in_packet_t *self,
    packet_t *packet
)
{
    return packet_pop_string(packet, &self->name)
        && packet_pop_u8(packet, &self->type);
}

void cl_user_logged_in_packet_destroy(cl_user_logged_in_packet_t *self)
{
    string_destroy(self->name);
    deallocate(self);
}
