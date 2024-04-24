/*
** EPITECH PROJECT, 2024
** state_get_team_by_name.c
** File description:
** state_get_team_by_name.c
*/

#include "state.h"

team_t *state_get_team_by_name(state_t *self, const string_t *name)
{
    team_t *team;

    for (size_t i = 0; i < VEC_LEN(self->teams); i++) {
        team = *(team_t **)VEC_AT(self->teams, i);
        if (!string_compare(team->name, name))
            return team;
    }
    return nullptr;
}
