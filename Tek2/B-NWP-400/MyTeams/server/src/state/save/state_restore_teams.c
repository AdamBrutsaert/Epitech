/*
** EPITECH PROJECT, 2024
** state_restore_teams.c
** File description:
** state_restore_teams.c
*/

#include "state.h"

#include "my/memory/file.h"

#include <stdio.h>

static bool team_already_exist(state_t *self, team_t *team)
{
    team_t *current;

    for (size_t i = 0; i < VEC_LEN(self->teams); i++) {
        current = *(team_t **)VEC_AT(self->teams, i);
        if (string_compare(current->uuid, team->uuid) == 0)
            return true;
        if (string_compare(current->name, team->name) == 0)
            return true;
    }
    return false;
}

static void parse_line(state_t *self, string_t *line)
{
    team_t *team = team_deserialize(line);

    if (team == nullptr)
        return;
    if (team_already_exist(self, team)) {
        team_destroy(team);
        return;
    }
    state_add_team(self, team);
    printf("[Restored] Team %s named %s: %s\n",
        STRING_CDATA(team->uuid), STRING_CDATA(team->name),
        STRING_CDATA(team->description)
    );
}

void state_restore_teams(state_t *self)
{
    file_t *file = file_create();
    string_t *content;
    vec_t *lines;

    if (!file_open(file, "teams.myteams", FILE_MODE_READ_ONLY)) {
        file_destroy(file);
        return;
    }
    content = file_read_all(file);
    file_destroy(file);
    lines = string_split(content, '\n');
    for (size_t i = 0; i < VEC_LEN(lines); i++)
        parse_line(self, *(string_t **)VEC_AT(lines, i));
    string_destroy(content);
    string_destroy_vec(lines);
}
