/*
** EPITECH PROJECT, 2024
** team_subscription_serialize.c
** File description:
** team_subscription_serialize.c
*/

#include "protocol/entities/team_subscription.h"

static string_t *escape(string_t *str)
{
    string_escape(str, ',');
    string_escape(str, '\n');
    return str;
}

string_t *team_subscription_serialize(const team_subscription_t *self)
{
    string_t *data = string_create();
    string_t *team_uuid = escape(string_clone(self->team_uuid));
    string_t *user_uuid = escape(string_clone(self->user_uuid));

    string_append_string(data, team_uuid);
    string_append_cstr(data, ",");
    string_append_string(data, user_uuid);
    string_append_cstr(data, "\n");
    string_destroy(team_uuid);
    string_destroy(user_uuid);
    return data;
}
