/*
** EPITECH PROJECT, 2024
** team_subscription_deserialize.c
** File description:
** team_subscription_deserialize.c
*/

#include "protocol/entities/team_subscription.h"

#include "my/memory/cstr.h"

team_subscription_t *team_subscription_deserialize(const string_t *data)
{
    vec_t *parts = string_split_escaped(data, ',');
    team_subscription_t *team_subscription;

    if (VEC_LEN(parts) != 2
        || !cstr_is_uuid(STRING_CDATA(*(string_t **)VEC_AT(parts, 0)))
        || !cstr_is_uuid(STRING_CDATA(*(string_t **)VEC_AT(parts, 1)))) {
        string_destroy_vec(parts);
        return nullptr;
    }
    team_subscription = team_subscription_create(
        *(string_t **)VEC_AT(parts, 0),
        *(string_t **)VEC_AT(parts, 1)
    );
    string_destroy_vec(parts);
    return team_subscription;
}
