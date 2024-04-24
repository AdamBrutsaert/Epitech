/*
** EPITECH PROJECT, 2024
** state_get_threads_of_channel.c
** File description:
** state_get_threads_of_channel.c
*/

#include "state.h"

vec_t *state_get_threads_of_channel(state_t *self, channel_t *channel)
{
    vec_t *threads = vec_create(sizeof(thread_t *));
    thread_t *thread;

    for (size_t i = 0; i < VEC_LEN(self->threads); i++) {
        thread = *(thread_t **)VEC_AT(self->threads, i);
        if (string_compare(thread->channel_uuid, channel->uuid) == 0)
            vec_push_back(threads, &thread);
    }
    return threads;
}
