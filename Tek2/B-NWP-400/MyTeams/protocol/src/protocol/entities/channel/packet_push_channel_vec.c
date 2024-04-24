/*
** EPITECH PROJECT, 2024
** packet_push_channel_vec.c
** File description:
** packet_push_channel_vec.c
*/

#include "protocol/entities/channel.h"

void packet_push_channel_vec(packet_t *self, const vec_t *channels)
{
    for (size_t i = 0; i < VEC_LEN(channels); i++)
        packet_push_channel(self, *(channel_t **)VEC_AT(channels, i));
    packet_push_u64(self, VEC_LEN(channels));
}
