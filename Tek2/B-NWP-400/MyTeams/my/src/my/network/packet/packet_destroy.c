/*
** EPITECH PROJECT, 2024
** packet_destroy.c
** File description:
** packet_destroy.c
*/

#include "my/network/packet.h"

void packet_destroy(packet_t *self)
{
    vec_destroy(self);
}
