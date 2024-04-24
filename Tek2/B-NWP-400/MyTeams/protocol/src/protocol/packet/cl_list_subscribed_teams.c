/*
** EPITECH PROJECT, 2024
** cl_list_subscribed_teams.c
** File description:
** cl_list_subscribed_teams.c
*/

#include "protocol/packet/list_subscribed_teams.h"

#include "my/memory/allocation.h"

void cl_list_subscribed_teams_packet_encode(
    cl_list_subscribed_teams_packet_t *self,
    packet_t *packet
)
{
    packet_push_u8(packet, self->type);
}

bool cl_list_subscribed_teams_packet_decode(
    cl_list_subscribed_teams_packet_t *self,
    packet_t *packet
)
{
    return packet_pop_u8(packet, &self->type);
}

void cl_list_subscribed_teams_packet_destroy(
    cl_list_subscribed_teams_packet_t *self
)
{
    deallocate(self);
}
