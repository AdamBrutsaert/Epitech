/*
** EPITECH PROJECT, 2024
** message_serialize.c
** File description:
** message_serialize.c
*/

#include "protocol/entities/message.h"

static string_t *escape(string_t *str)
{
    string_escape(str, ',');
    string_escape(str, '\n');
    return str;
}

string_t *message_serialize(const message_t *self)
{
    string_t *data = string_create();
    string_t *from = escape(string_clone(self->from_uuid));
    string_t *to = escape(string_clone(self->to_uuid));
    string_t *msg = escape(string_clone(self->message));
    string_t *ts = escape(string_create_from_unsigned(self->timestamp));

    string_append_string(data, from);
    string_append_cstr(data, ",");
    string_append_string(data, to);
    string_append_cstr(data, ",");
    string_append_string(data, msg);
    string_append_cstr(data, ",");
    string_append_string(data, ts);
    string_append_cstr(data, "\n");
    string_destroy(from);
    string_destroy(to);
    string_destroy(msg);
    string_destroy(ts);
    return data;
}
