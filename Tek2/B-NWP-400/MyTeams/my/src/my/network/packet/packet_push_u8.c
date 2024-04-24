/*
** EPITECH PROJECT, 2024
** packet_push_u8.c
** File description:
** packet_push_u8.c
*/

#include "my/network/packet.h"

#include <netinet/in.h>

void packet_push_u8(packet_t *self, uint8_t value)
{
    vec_push_back(self, &value);
}
