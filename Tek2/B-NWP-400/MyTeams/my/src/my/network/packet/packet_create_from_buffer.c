/*
** EPITECH PROJECT, 2024
** packet_create_from_buffer.c
** File description:
** packet_create_from_buffer.c
*/

#include "my/network/packet.h"

packet_t *packet_create_from_buffer(const void *buffer, size_t size)
{
    packet_t *self = vec_create(sizeof(uint8_t));

    vec_push_back_some(self, buffer, size);
    return self;
}
