/*
** EPITECH PROJECT, 2024
** packet_push_u32.c
** File description:
** packet_push_u32.c
*/

#include "my/network/packet.h"

#include <netinet/in.h>

void packet_push_u32(packet_t *self, uint32_t value)
{
    value = htonl(value);
    vec_push_back_some(self, &value, sizeof(value));
}
