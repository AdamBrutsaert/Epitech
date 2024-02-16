/*
** EPITECH PROJECT, 2023
** network_connect.c
** File description:
** network_connect.c
*/

#include "network.h"

int8_t network_connect(pid_t pid, bit_t bit)
{
    network_peer(SET, &pid);
    if (network_send_bit(bit) == 84)
        return 84;
    if (bit == BIT_1)
        return 84;
    return 0;
}
