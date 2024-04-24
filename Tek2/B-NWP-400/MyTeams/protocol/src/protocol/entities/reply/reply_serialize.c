/*
** EPITECH PROJECT, 2024
** reply_serialize.c
** File description:
** reply_serialize.c
*/

#include "protocol/entities/reply.h"

static string_t *escape(string_t *str)
{
    string_escape(str, ',');
    string_escape(str, '\n');
    return str;
}

string_t *reply_serialize(const reply_t *self)
{
    string_t *data = string_create();
    string_t *thread_uuid = escape(string_clone(self->thread_uuid));
    string_t *user_uuid = escape(string_clone(self->user_uuid));
    string_t *ts = escape(string_create_from_unsigned(self->timestamp));
    string_t *body = escape(string_clone(self->body));

    string_append_string(data, thread_uuid);
    string_append_cstr(data, ",");
    string_append_string(data, user_uuid);
    string_append_cstr(data, ",");
    string_append_string(data, ts);
    string_append_cstr(data, ",");
    string_append_string(data, body);
    string_append_cstr(data, "\n");
    string_destroy(thread_uuid);
    string_destroy(user_uuid);
    string_destroy(ts);
    string_destroy(body);
    return data;
}
