/*
** EPITECH PROJECT, 2024
** message_deserialize.c
** File description:
** message_deserialize.c
*/

#include "protocol/entities/message.h"

#include "my/memory/cstr.h"

message_t *message_deserialize(const string_t *data)
{
    vec_t *parts = string_split_escaped(data, ',');
    uint64_t ts;
    message_t *msg;

    if (VEC_LEN(parts) != 4
        || !cstr_to_u64(STRING_CDATA(*(string_t **)VEC_AT(parts, 3)), &ts)) {
        string_destroy_vec(parts);
        return nullptr;
    }
    msg = message_create(
        *(string_t **)VEC_AT(parts, 0),
        *(string_t **)VEC_AT(parts, 1),
        *(string_t **)VEC_AT(parts, 2),
        ts
    );
    string_destroy_vec(parts);
    return msg;
}
