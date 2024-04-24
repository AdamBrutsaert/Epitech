/*
** EPITECH PROJECT, 2024
** state_save_team_subscriptions.c
** File description:
** state_save_team_subscriptions.c
*/

#include "state.h"

#include "my/memory/file.h"

void state_save_team_subscriptions(state_t *self)
{
    file_t *file = file_create();
    team_subscription_t *sub;
    string_t *line;

    if (!file_open(file, "team_subscriptions.myteams",
        FILE_MODE_WRITE_ONLY | FILE_MODE_CREATE | FILE_MODE_TRUNC)) {
        file_destroy(file);
        return;
    }
    for (size_t i = 0; i < VEC_LEN(self->team_subscriptions); i++) {
        sub = *(team_subscription_t **)VEC_AT(self->team_subscriptions, i);
        line = team_subscription_serialize(sub);
        file_write_all(file, STRING_CDATA(line), STRING_LEN(line));
        string_destroy(line);
    }
    file_destroy(file);
}
