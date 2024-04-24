/*
** EPITECH PROJECT, 2024
** packet_pop_message_vec.c
** File description:
** packet_pop_message_vec.c
*/

#include "protocol/entities/message.h"

static void destroy_vec(vec_t *vec)
{
    for (size_t i = 0; i < VEC_LEN(vec); i++)
        message_destroy(*(message_t **)VEC_AT(vec, i));
    vec_destroy(vec);
}

bool packet_pop_message_vec(packet_t *self, vec_t **messages)
{
    uint64_t count;
    message_t *user;

    if (!packet_pop_u64(self, &count))
        return false;
    *messages = vec_create(sizeof(message_t));
    for (size_t i = 0; i < count; i++) {
        if (!packet_pop_message(self, &user)) {
            destroy_vec(*messages);
            return false;
        }
        vec_push_back(*messages, &user);
    }
    return true;
}
