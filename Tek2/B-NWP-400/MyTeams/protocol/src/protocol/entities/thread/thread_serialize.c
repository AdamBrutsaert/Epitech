/*
** EPITECH PROJECT, 2024
** thread_serialize.c
** File description:
** thread_serialize.c
*/

#include "protocol/entities/thread.h"

static string_t *escape(string_t *str)
{
    string_escape(str, ',');
    string_escape(str, '\n');
    return str;
}

static void serialize_end(const thread_t *self, string_t *data)
{
    string_t *timestamp = escape(string_create_from_unsigned(self->timestamp));
    string_t *title = escape(string_clone(self->title));
    string_t *body = escape(string_clone(self->body));

    string_append_string(data, timestamp);
    string_append_cstr(data, ",");
    string_append_string(data, title);
    string_append_cstr(data, ",");
    string_append_string(data, body);
    string_append_cstr(data, "\n");
    string_destroy(timestamp);
    string_destroy(title);
    string_destroy(body);
}

string_t *thread_serialize(const thread_t *self)
{
    string_t *data = string_create();
    string_t *uuid = escape(string_clone(self->uuid));
    string_t *channel_uuid = escape(string_clone(self->channel_uuid));
    string_t *user_uuid = escape(string_clone(self->user_uuid));

    string_append_string(data, uuid);
    string_append_cstr(data, ",");
    string_append_string(data, channel_uuid);
    string_append_cstr(data, ",");
    string_append_string(data, user_uuid);
    string_append_cstr(data, ",");
    serialize_end(self, data);
    string_destroy(uuid);
    string_destroy(channel_uuid);
    string_destroy(user_uuid);
    return data;
}
