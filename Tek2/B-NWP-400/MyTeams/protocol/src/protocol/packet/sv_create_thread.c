/*
** EPITECH PROJECT, 2024
** sv_create_thread.c
** File description:
** sv_create_thread.c
*/

#include "protocol/packet/create_thread.h"
#include "my/memory/allocation.h"

void sv_create_thread_packet_encode(
    sv_create_thread_packet_t *self,
    packet_t *packet
)
{
    packet_push_u8(packet, self->type);
    packet_push_thread(packet, self->thread);
}

bool sv_create_thread_packet_decode(
    sv_create_thread_packet_t *self,
    packet_t *packet
)
{
    return packet_pop_thread(packet, &self->thread)
        && packet_pop_u8(packet, &self->type);
}

void sv_create_thread_packet_destroy(sv_create_thread_packet_t *self)
{
    thread_destroy(self->thread);
    deallocate(self);
}
