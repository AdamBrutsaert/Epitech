/*
** EPITECH PROJECT, 2024
** packet_pop_user_vec.c
** File description:
** packet_pop_user_vec.c
*/

#include "protocol/entities/user.h"

static void destroy_vec(vec_t *vec)
{
    for (size_t i = 0; i < VEC_LEN(vec); i++)
        user_destroy(*(user_t **)VEC_AT(vec, i));
    vec_destroy(vec);
}

bool packet_pop_user_vec(packet_t *self, vec_t **users)
{
    uint64_t user_count;
    user_t *user;

    if (!packet_pop_u64(self, &user_count))
        return false;
    *users = vec_create(sizeof(user_t));
    for (size_t i = 0; i < user_count; i++) {
        if (!packet_pop_user(self, &user)) {
            destroy_vec(*users);
            return false;
        }
        vec_push_back(*users, &user);
    }
    return true;
}
