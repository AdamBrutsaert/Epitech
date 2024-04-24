/*
** EPITECH PROJECT, 2024
** packet_pop_string.c
** File description:
** packet_pop_string.c
*/

#include "my/network/packet.h"

bool packet_pop_string(packet_t *self, string_t **string)
{
    uint64_t length;

    if (!packet_pop_u64(self, &length))
        return false;
    if (VEC_LEN(self) < length)
        return false;
    *string = string_create_from_buffer(
        VEC_AT(self, VEC_LEN(self) - length),
        length
    );
    vec_pop_some_back(self, length);
    return true;
}
