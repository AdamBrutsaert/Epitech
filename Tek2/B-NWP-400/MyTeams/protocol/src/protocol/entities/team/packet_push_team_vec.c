/*
** EPITECH PROJECT, 2024
** packet_push_team_vec.c
** File description:
** packet_push_team_vec.c
*/

#include "protocol/entities/team.h"

void packet_push_team_vec(packet_t *self, const vec_t *teams)
{
    for (size_t i = 0; i < VEC_LEN(teams); i++)
        packet_push_team(self, *(team_t **)VEC_AT(teams, i));
    packet_push_u64(self, VEC_LEN(teams));
}
