/*
** EPITECH PROJECT, 2024
** packet_pop_channel_vec.c
** File description:
** packet_pop_channel_vec.c
*/

#include "protocol/entities/channel.h"

static void destroy_vec(vec_t *vec)
{
    for (size_t i = 0; i < VEC_LEN(vec); i++)
        channel_destroy(*(channel_t **)VEC_AT(vec, i));
    vec_destroy(vec);
}

bool packet_pop_channel_vec(packet_t *self, vec_t **channels)
{
    uint64_t count;
    channel_t *user;

    if (!packet_pop_u64(self, &count))
        return false;
    *channels = vec_create(sizeof(channel_t));
    for (size_t i = 0; i < count; i++) {
        if (!packet_pop_channel(self, &user)) {
            destroy_vec(*channels);
            return false;
        }
        vec_push_back(*channels, &user);
    }
    return true;
}
