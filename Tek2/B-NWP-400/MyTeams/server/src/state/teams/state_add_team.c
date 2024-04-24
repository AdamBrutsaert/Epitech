/*
** EPITECH PROJECT, 2024
** state_add_team.c
** File description:
** state_add_team.c
*/

#include "state.h"

void state_add_team(state_t *self, team_t *team)
{
    vec_push_back(self->teams, &team);
}
