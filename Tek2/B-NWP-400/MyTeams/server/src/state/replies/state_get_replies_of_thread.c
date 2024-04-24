/*
** EPITECH PROJECT, 2024
** state_get_replies_of_thread.c
** File description:
** state_get_replies_of_thread.c
*/

#include "state.h"

vec_t *state_get_replies_of_thread(state_t *self, thread_t *thread)
{
    vec_t *replies = vec_create(sizeof(reply_t *));
    reply_t *reply;

    for (size_t i = 0; i < VEC_LEN(self->replies); i++) {
        reply = *(reply_t **)VEC_AT(self->replies, i);
        if (string_compare(reply->thread_uuid, thread->uuid) == 0)
            vec_push_back(replies, &reply);
    }
    return replies;
}
