/*
** EPITECH PROJECT, 2024
** sv_created_thread_succesfully.c
** File description:
** sv_created_thread_succesfully.c
*/

#include "protocol/packet/create_thread.h"

#include "my/memory/allocation.h"

void sv_created_thread_successfully_packet_encode(
    sv_created_thread_successfully_packet_t *self,
    packet_t *packet
)
{
    packet_push_u8(packet, self->type);
    packet_push_thread(packet, self->thread);
}

bool sv_created_thread_successfully_packet_decode(
    sv_created_thread_successfully_packet_t *self,
    packet_t *packet
)
{
    return packet_pop_thread(packet, &self->thread)
        && packet_pop_u8(packet, &self->type);
}

void sv_created_thread_successfully_packet_destroy(
    sv_created_thread_successfully_packet_t *self
)
{
    thread_destroy(self->thread);
    deallocate(self);
}
