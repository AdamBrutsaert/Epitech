/*
** EPITECH PROJECT, 2024
** packet_push_u16.c
** File description:
** packet_push_u16.c
*/

#include "my/network/packet.h"

#include <netinet/in.h>

void packet_push_u16(packet_t *self, uint16_t value)
{
    value = htons(value);
    vec_push_back_some(self, &value, sizeof(value));
}
