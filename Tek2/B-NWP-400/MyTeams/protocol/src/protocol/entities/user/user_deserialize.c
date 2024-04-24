/*
** EPITECH PROJECT, 2024
** user_deserialize.c
** File description:
** user_deserialize.c
*/

#include "protocol/entities/user.h"

#include "my/memory/cstr.h"

user_t *user_deserialize(const string_t *data)
{
    vec_t *parts = string_split_escaped(data, ',');
    user_t *user;

    if (VEC_LEN(parts) != 2
        || !cstr_is_uuid(STRING_CDATA(*(string_t **)VEC_AT(parts, 0)))) {
        string_destroy_vec(parts);
        return nullptr;
    }
    user = user_load(
        *(string_t **)VEC_AT(parts, 0),
        *(string_t **)VEC_AT(parts, 1)
    );
    string_destroy_vec(parts);
    return user;
}
