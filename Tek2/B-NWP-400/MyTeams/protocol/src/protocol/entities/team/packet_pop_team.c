/*
** EPITECH PROJECT, 2024
** packet_pop_team.c
** File description:
** packet_pop_team.c
*/

#include "protocol/entities/team.h"

#include "my/memory/allocation.h"

bool packet_pop_team(packet_t *self, team_t **team)
{
    string_t *uuid;
    string_t *name;
    string_t *description;

    if (!packet_pop_string(self, &description))
        return false;
    if (!packet_pop_string(self, &name)) {
        string_destroy(description);
        return false;
    }
    if (!packet_pop_string(self, &uuid)) {
        string_destroy(description);
        string_destroy(name);
        return false;
    }
    *team = allocate(sizeof(team_t));
    **team = (team_t){uuid, name, description};
    return true;
}
