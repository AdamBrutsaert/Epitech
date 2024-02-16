/*
** EPITECH PROJECT, 2023
** network_send_bit.c
** File description:
** network_send_bit.c
*/

#include "network.h"

#include <unistd.h>

int8_t network_send_bit(bit_t bit)
{
    pid_t peer = -1;

    network_peer(GET, &peer);
    if (peer == -1)
        return 84;
    if (kill(peer, bit == BIT_0 ? SIGUSR1 : SIGUSR2) == -1)
        return 84;
    return 0;
}
