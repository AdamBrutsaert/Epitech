/*
** EPITECH PROJECT, 2024
** sv_create_team.c
** File description:
** sv_create_team.c
*/

#include "protocol/packet/create_team.h"
#include "my/memory/allocation.h"

void sv_create_team_packet_encode(
    sv_create_team_packet_t *self,
    packet_t *packet
)
{
    packet_push_u8(packet, self->type);
    packet_push_team(packet, self->team);
}

bool sv_create_team_packet_decode(
    sv_create_team_packet_t *self,
    packet_t *packet
)
{
    return packet_pop_team(packet, &self->team)
        && packet_pop_u8(packet, &self->type);
}

void sv_create_team_packet_destroy(sv_create_team_packet_t *self)
{
    team_destroy(self->team);
    deallocate(self);
}
