/*
** EPITECH PROJECT, 2024
** channel_deserialize.c
** File description:
** channel_deserialize.c
*/

#include "protocol/entities/channel.h"

#include "my/memory/cstr.h"

channel_t *channel_deserialize(const string_t *data)
{
    vec_t *parts = string_split_escaped(data, ',');
    channel_t *channel;

    if (VEC_LEN(parts) != 4
        || !cstr_is_uuid(STRING_CDATA(*(string_t **)VEC_AT(parts, 0)))
        || !cstr_is_uuid(STRING_CDATA(*(string_t **)VEC_AT(parts, 1)))) {
        string_destroy_vec(parts);
        return nullptr;
    }
    channel = channel_load(
        *(string_t **)VEC_AT(parts, 0),
        *(string_t **)VEC_AT(parts, 1),
        *(string_t **)VEC_AT(parts, 2),
        *(string_t **)VEC_AT(parts, 3)
    );
    string_destroy_vec(parts);
    return channel;
}
