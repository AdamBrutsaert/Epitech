/*
** EPITECH PROJECT, 2024
** sv_unsubscribe_from_team.c
** File description:
** sv_unsubscribe_from_team.c
*/

#include "protocol/packet/unsubscribe_from_team.h"

#include "my/memory/allocation.h"

void sv_unsubscribe_from_team_packet_encode(
    sv_unsubscribe_from_team_packet_t *self,
    packet_t *packet
)
{
    packet_push_u8(packet, self->type);
    packet_push_team_subscription(packet, self->team_subscription);
}

bool sv_unsubscribe_from_team_packet_decode(
    sv_unsubscribe_from_team_packet_t *self,
    packet_t *packet
)
{
    return packet_pop_team_subscription(packet, &self->team_subscription)
        && packet_pop_u8(packet, &self->type);
}

void sv_unsubscribe_from_team_packet_destroy(
    sv_unsubscribe_from_team_packet_t *self
)
{
    team_subscription_destroy(self->team_subscription);
    deallocate(self);
}
