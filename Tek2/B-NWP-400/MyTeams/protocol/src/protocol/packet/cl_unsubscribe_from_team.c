/*
** EPITECH PROJECT, 2024
** cl_unsubscribe_from_team.c
** File description:
** cl_unsubscribe_from_team.c
*/

#include "protocol/packet/unsubscribe_from_team.h"

#include "my/memory/allocation.h"

void cl_unsubscribe_from_team_packet_encode(
    cl_unsubscribe_from_team_packet_t *self,
    packet_t *packet
)
{
    packet_push_u8(packet, self->type);
    packet_push_string(packet, self->uuid);
}

bool cl_unsubscribe_from_team_packet_decode(
    cl_unsubscribe_from_team_packet_t *self,
    packet_t *packet
)
{
    return packet_pop_string(packet, &self->uuid)
        && packet_pop_u8(packet, &self->type);
}

void cl_unsubscribe_from_team_packet_destroy(
    cl_unsubscribe_from_team_packet_t *self
)
{
    string_destroy(self->uuid);
    deallocate(self);
}
