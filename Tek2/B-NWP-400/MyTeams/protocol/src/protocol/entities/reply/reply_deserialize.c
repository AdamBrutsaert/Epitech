/*
** EPITECH PROJECT, 2024
** reply_deserialize.c
** File description:
** reply_deserialize.c
*/

#include "protocol/entities/reply.h"

#include "my/memory/cstr.h"

reply_t *reply_deserialize(const string_t *data)
{
    vec_t *parts = string_split_escaped(data, ',');
    reply_t *reply;
    uint64_t ts;

    if (VEC_LEN(parts) != 4
        || !cstr_is_uuid(STRING_CDATA(*(string_t **)VEC_AT(parts, 0)))
        || !cstr_is_uuid(STRING_CDATA(*(string_t **)VEC_AT(parts, 1)))
        || !cstr_to_u64(STRING_CDATA(*(string_t **)VEC_AT(parts, 2)), &ts)) {
        string_destroy_vec(parts);
        return nullptr;
    }
    reply = reply_create(
        *(string_t **)VEC_AT(parts, 0),
        *(string_t **)VEC_AT(parts, 1),
        ts,
        *(string_t **)VEC_AT(parts, 3)
    );
    string_destroy_vec(parts);
    return reply;
}
