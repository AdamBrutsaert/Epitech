/*
** EPITECH PROJECT, 2024
** packet_push_u64.c
** File description:
** packet_push_u64.c
*/

#include "my/network/packet.h"

#include <netinet/in.h>

void packet_push_u64(packet_t *self, uint64_t v)
{
    if (htonl(1) == 1) {
        vec_push_back_some(self, &v, sizeof(v));
        return;
    }
    v = ((uint64_t)htonl((v) & 0xFFFFFFFF) << 32) | htonl((v) >> 32);
    vec_push_back_some(self, &v, sizeof(v));
}
