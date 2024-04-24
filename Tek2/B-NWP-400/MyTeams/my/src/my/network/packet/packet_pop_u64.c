/*
** EPITECH PROJECT, 2024
** packet_pop_u64.c
** File description:
** packet_pop_u64.c
*/

#include "my/network/packet.h"

#include <netinet/in.h>

bool packet_pop_u64(packet_t *self, uint64_t *v)
{
    if (VEC_LEN(self) < sizeof(uint64_t))
        return false;
    *v = *(uint64_t *)VEC_AT(self, VEC_LEN(self) - sizeof(uint64_t));
    vec_pop_some_back(self, sizeof(uint64_t));
    if (ntohl(1) == 1)
        return true;
    *v = ((uint64_t)ntohl((*v) & 0xFFFFFFFF) << 32) | ntohl((*v) >> 32);
    return true;
}
