/*
** EPITECH PROJECT, 2024
** state_save_teams.c
** File description:
** state_save_teams.c
*/

#include "state.h"

#include "my/memory/file.h"

void state_save_teams(state_t *self)
{
    file_t *file = file_create();
    team_t *team;
    string_t *line;

    if (!file_open(file, "teams.myteams",
        FILE_MODE_WRITE_ONLY | FILE_MODE_CREATE | FILE_MODE_TRUNC)) {
        file_destroy(file);
        return;
    }
    for (size_t i = 0; i < VEC_LEN(self->teams); i++) {
        team = *(team_t **)VEC_AT(self->teams, i);
        line = team_serialize(team);
        file_write_all(file, STRING_CDATA(line), STRING_LEN(line));
        string_destroy(line);
    }
    file_destroy(file);
}
