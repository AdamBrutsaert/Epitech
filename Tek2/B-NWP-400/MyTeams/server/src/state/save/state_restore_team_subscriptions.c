/*
** EPITECH PROJECT, 2024
** state_restore_team_subscriptions.c
** File description:
** state_restore_team_subscriptions.c
*/

#include "state.h"

#include "my/memory/file.h"

#include <stdio.h>

static void parse_line(state_t *self, string_t *line)
{
    team_subscription_t *sub = team_subscription_deserialize(line);

    if (sub == nullptr)
        return;
    if (!state_get_team_by_uuid(self, sub->team_uuid)
        || !state_get_user_by_uuid(self, sub->user_uuid)) {
        team_subscription_destroy(sub);
        return;
    }
    state_add_subscription(self, sub);
    printf("[Restored] Team subscription to %s of %s \n",
        STRING_CDATA(sub->team_uuid), STRING_CDATA(sub->user_uuid));
}

void state_restore_team_subscriptions(state_t *self)
{
    file_t *file = file_create();
    string_t *content;
    vec_t *lines;

    if (!file_open(file, "team_subscriptions.myteams", FILE_MODE_READ_ONLY)) {
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
