/*
** EPITECH PROJECT, 2024
** packet_pop_team_vec.c
** File description:
** packet_pop_team_vec.c
*/

#include "protocol/entities/team.h"

static void destroy_vec(vec_t *vec)
{
    for (size_t i = 0; i < VEC_LEN(vec); i++)
        team_destroy(*(team_t **)VEC_AT(vec, i));
    vec_destroy(vec);
}

bool packet_pop_team_vec(packet_t *self, vec_t **teams)
{
    uint64_t count;
    team_t *user;

    if (!packet_pop_u64(self, &count))
        return false;
    *teams = vec_create(sizeof(team_t));
    for (size_t i = 0; i < count; i++) {
        if (!packet_pop_team(self, &user)) {
            destroy_vec(*teams);
            return false;
        }
        vec_push_back(*teams, &user);
    }
    return true;
}
