/*
** EPITECH PROJECT, 2024
** sv_list_threads.c
** File description:
** sv_list_threads.c
*/

#include "protocol/packet/list_threads.h"

#include "protocol/entities/thread.h"
#include "my/memory/allocation.h"

void sv_list_threads_packet_encode(
    sv_list_threads_packet_t *self,
    packet_t *packet
)
{
    packet_push_u8(packet, self->type);
    packet_push_thread_vec(packet, self->threads);
}

bool sv_list_threads_packet_decode(
    sv_list_threads_packet_t *self,
    packet_t *packet
)
{
    return packet_pop_thread_vec(packet, &self->threads)
        && packet_pop_u8(packet, &self->type);
}

void sv_list_threads_packet_destroy(sv_list_threads_packet_t *self)
{
    for (size_t i = 0; i < VEC_LEN(self->threads); i++)
        thread_destroy(*(thread_t **)VEC_AT(self->threads, i));
    vec_destroy(self->threads);
    deallocate(self);
}
