/*
** EPITECH PROJECT, 2024
** packet_pop_u16.c
** File description:
** packet_pop_u16.c
*/

#include "my/network/packet.h"

#include <netinet/in.h>

bool packet_pop_u16(packet_t *self, uint16_t *value)
{
    if (VEC_LEN(self) < 2)
        return false;
    *value = ntohs(*(uint16_t *)VEC_AT(self, VEC_LEN(self) - 2));
    vec_pop_some_back(self, 2);
    return true;
}
