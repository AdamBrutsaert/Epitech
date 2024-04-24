/*
** EPITECH PROJECT, 2024
** packet_push_string.c
** File description:
** packet_push_string.c
*/

#include "my/network/packet.h"

void packet_push_string(packet_t *self, const string_t *string)
{
    vec_push_back_some(self, STRING_CDATA(string), STRING_LEN(string));
    packet_push_u64(self, STRING_LEN(string));
}
