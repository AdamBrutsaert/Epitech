/*
** EPITECH PROJECT, 2024
** packet_pop_u8.c
** File description:
** packet_pop_u8.c
*/

#include "my/network/packet.h"

bool packet_pop_u8(packet_t *self, uint8_t *value)
{
    if (VEC_LEN(self) < 1)
        return false;
    *value = *(uint8_t *)VEC_AT(self, VEC_LEN(self) - 1);
    vec_pop_back(self);
    return true;
}
