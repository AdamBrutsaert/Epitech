/*
** EPITECH PROJECT, 2024
** user_serialize.c
** File description:
** user_serialize.c
*/

#include "protocol/entities/user.h"

string_t *user_serialize(const user_t *self)
{
    string_t *data = string_create();
    string_t *uuid = string_clone(self->uuid);
    string_t *name = string_clone(self->name);

    string_escape(uuid, ',');
    string_escape(name, ',');
    string_escape(uuid, '\n');
    string_escape(name, '\n');
    string_append_string(data, uuid);
    string_append_cstr(data, ",");
    string_append_string(data, name);
    string_append_cstr(data, "\n");
    string_destroy(uuid);
    string_destroy(name);
    return data;
}
