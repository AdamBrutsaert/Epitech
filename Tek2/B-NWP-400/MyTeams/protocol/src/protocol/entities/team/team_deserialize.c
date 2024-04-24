/*
** EPITECH PROJECT, 2024
** team_deserialize.c
** File description:
** team_deserialize.c
*/

#include "protocol/entities/team.h"

#include "my/memory/cstr.h"

team_t *team_deserialize(const string_t *data)
{
    vec_t *parts = string_split_escaped(data, ',');
    team_t *team;

    if (VEC_LEN(parts) != 3
        || !cstr_is_uuid(STRING_CDATA(*(string_t **)VEC_AT(parts, 0)))) {
        string_destroy_vec(parts);
        return nullptr;
    }
    team = team_load(
        *(string_t **)VEC_AT(parts, 0),
        *(string_t **)VEC_AT(parts, 1),
        *(string_t **)VEC_AT(parts, 2)
    );
    string_destroy_vec(parts);
    return team;
}
