/*
** EPITECH PROJECT, 2024
** sv_list_subscribed_teams.c
** File description:
** sv_list_subscribed_teams.c
*/

#include "protocol/packet/list_subscribed_teams.h"

#include "protocol/entities/team.h"
#include "my/memory/allocation.h"

void sv_list_subscribed_teams_packet_encode(
    sv_list_subscribed_teams_packet_t *self,
    packet_t *packet
)
{
    packet_push_u8(packet, self->type);
    packet_push_team_vec(packet, self->teams);
}

bool sv_list_subscribed_teams_packet_decode(
    sv_list_subscribed_teams_packet_t *self,
    packet_t *packet
)
{
    return packet_pop_team_vec(packet, &self->teams)
        && packet_pop_u8(packet, &self->type);
}

void sv_list_subscribed_teams_packet_destroy(
    sv_list_subscribed_teams_packet_t *self
)
{
    for (size_t i = 0; i < VEC_LEN(self->teams); i++)
        team_destroy(*(team_t **)VEC_AT(self->teams, i));
    vec_destroy(self->teams);
    deallocate(self);
}
