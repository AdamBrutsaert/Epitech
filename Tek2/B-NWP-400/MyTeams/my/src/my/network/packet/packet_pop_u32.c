/*
** EPITECH PROJECT, 2024
** packet_pop_u32.c
** File description:
** packet_pop_u32.c
*/

#include "my/network/packet.h"

#include <netinet/in.h>

bool packet_pop_u32(packet_t *self, uint32_t *value)
{
    if (VEC_LEN(self) < 4)
        return false;
    *value = ntohl(*(uint32_t *)VEC_AT(self, VEC_LEN(self) - 4));
    vec_pop_some_back(self, 4);
    return true;
}
