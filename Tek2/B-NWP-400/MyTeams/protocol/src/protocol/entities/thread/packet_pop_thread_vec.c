/*
** EPITECH PROJECT, 2024
** packet_pop_thread_vec.c
** File description:
** packet_pop_thread_vec.c
*/

#include "protocol/entities/thread.h"

static void destroy_vec(vec_t *vec)
{
    for (size_t i = 0; i < VEC_LEN(vec); i++)
        thread_destroy(*(thread_t **)VEC_AT(vec, i));
    vec_destroy(vec);
}

bool packet_pop_thread_vec(packet_t *self, vec_t **threads)
{
    uint64_t count;
    thread_t *user;

    if (!packet_pop_u64(self, &count))
        return false;
    *threads = vec_create(sizeof(thread_t));
    for (size_t i = 0; i < count; i++) {
        if (!packet_pop_thread(self, &user)) {
            destroy_vec(*threads);
            return false;
        }
        vec_push_back(*threads, &user);
    }
    return true;
}
