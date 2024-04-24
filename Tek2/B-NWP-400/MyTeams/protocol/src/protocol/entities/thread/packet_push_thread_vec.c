/*
** EPITECH PROJECT, 2024
** packet_push_thread_vec.c
** File description:
** packet_push_thread_vec.c
*/

#include "protocol/entities/thread.h"

void packet_push_thread_vec(packet_t *self, const vec_t *threads)
{
    for (size_t i = 0; i < VEC_LEN(threads); i++)
        packet_push_thread(self, *(thread_t **)VEC_AT(threads, i));
    packet_push_u64(self, VEC_LEN(threads));
}
