/*
** EPITECH PROJECT, 2024
** packet_push_team.c
** File description:
** packet_push_team.c
*/

#include "protocol/entities/team.h"

void packet_push_team(packet_t *self, const team_t *team)
{
    packet_push_string(self, team->uuid);
    packet_push_string(self, team->name);
    packet_push_string(self, team->description);
}
