/*
** EPITECH PROJECT, 2024
** channel_serialize.c
** File description:
** channel_serialize.c
*/

#include "protocol/entities/channel.h"

static string_t *escape(string_t *str)
{
    string_escape(str, ',');
    string_escape(str, '\n');
    return str;
}

string_t *channel_serialize(const channel_t *self)
{
    string_t *data = string_create();
    string_t *uuid = escape(string_clone(self->uuid));
    string_t *team_uuid = escape(string_clone(self->team_uuid));
    string_t *name = escape(string_clone(self->name));
    string_t *desc = escape(string_clone(self->description));

    string_append_string(data, uuid);
    string_append_cstr(data, ",");
    string_append_string(data, team_uuid);
    string_append_cstr(data, ",");
    string_append_string(data, name);
    string_append_cstr(data, ",");
    string_append_string(data, desc);
    string_append_cstr(data, "\n");
    string_destroy(uuid);
    string_destroy(team_uuid);
    string_destroy(name);
    string_destroy(desc);
    return data;
}
