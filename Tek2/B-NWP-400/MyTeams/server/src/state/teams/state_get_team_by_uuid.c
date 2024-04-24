/*
** EPITECH PROJECT, 2024
** state_get_team_by_uuid.c
** File description:
** state_get_team_by_uuid.c
*/

#include "state.h"

team_t *state_get_team_by_uuid(state_t *self, const string_t *uuid)
{
    team_t *team;

    for (size_t i = 0; i < VEC_LEN(self->teams); i++) {
        team = *(team_t **)VEC_AT(self->teams, i);
        if (!string_compare(team->uuid, uuid))
            return team;
    }
    return nullptr;
}
