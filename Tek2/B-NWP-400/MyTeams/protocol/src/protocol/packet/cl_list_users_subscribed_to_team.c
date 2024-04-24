/*
** EPITECH PROJECT, 2024
** cl_list_users_subscribed_to_team.c
** File description:
** cl_list_users_subscribed_to_team.c
*/

#include "protocol/packet/list_users_subscribed_to_team.h"

#include "my/memory/allocation.h"

void cl_list_users_subscribed_to_team_packet_encode(
    cl_list_users_subscribed_to_team_packet_t *self,
    packet_t *packet
)
{
    packet_push_u8(packet, self->type);
    packet_push_string(packet, self->uuid);
}

bool cl_list_users_subscribed_to_team_packet_decode(
    cl_list_users_subscribed_to_team_packet_t *self,
    packet_t *packet
)
{
    return packet_pop_string(packet, &self->uuid)
        && packet_pop_u8(packet, &self->type);
}

void cl_list_users_subscribed_to_team_packet_destroy(
    cl_list_users_subscribed_to_team_packet_t *self
)
{
    string_destroy(self->uuid);
    deallocate(self);
}
