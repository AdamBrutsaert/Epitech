/*
** EPITECH PROJECT, 2024
** sv_get_thread_info.c
** File description:
** sv_get_thread_info.c
*/

#include "protocol/packet/get_thread_info.h"
#include "my/memory/allocation.h"

void sv_get_thread_info_packet_encode(
    sv_get_thread_info_packet_t *self,
    packet_t *packet
)
{
    packet_push_u8(packet, self->type);
    packet_push_thread(packet, self->thread);
}

bool sv_get_thread_info_packet_decode(
    sv_get_thread_info_packet_t *self,
    packet_t *packet
)
{
    return packet_pop_thread(packet, &self->thread)
        && packet_pop_u8(packet, &self->type);
}

void sv_get_thread_info_packet_destroy(
    sv_get_thread_info_packet_t *self
)
{
    thread_destroy(self->thread);
    deallocate(self);
}
