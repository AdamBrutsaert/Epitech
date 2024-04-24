/*
** EPITECH PROJECT, 2024
** packet_create.c
** File description:
** packet_create.c
*/

#include "my/network/packet.h"

packet_t *packet_create(void)
{
    return vec_create(sizeof(uint8_t));
}
