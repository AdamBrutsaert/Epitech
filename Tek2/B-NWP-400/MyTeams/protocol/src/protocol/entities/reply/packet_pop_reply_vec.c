/*
** EPITECH PROJECT, 2024
** packet_pop_reply_vec.c
** File description:
** packet_pop_reply_vec.c
*/

#include "protocol/entities/reply.h"

static void destroy_vec(vec_t *vec)
{
    for (size_t i = 0; i < VEC_LEN(vec); i++)
        reply_destroy(*(reply_t **)VEC_AT(vec, i));
    vec_destroy(vec);
}

bool packet_pop_reply_vec(packet_t *self, vec_t **replys)
{
    uint64_t count;
    reply_t *user;

    if (!packet_pop_u64(self, &count))
        return false;
    *replys = vec_create(sizeof(reply_t));
    for (size_t i = 0; i < count; i++) {
        if (!packet_pop_reply(self, &user)) {
            destroy_vec(*replys);
            return false;
        }
        vec_push_back(*replys, &user);
    }
    return true;
}
