/*
** EPITECH PROJECT, 2023
** network_receive_bit.c
** File description:
** network_receive_bit.c
*/

#include "network.h"

#include <unistd.h>

bit_t network_receive_bit(void)
{
    uint64_t length = 0;
    bit_t bit;

    while (length < 1) {
        pause();
        network_buffer(LENGTH, &length);
    }
    network_buffer(POP, &bit);
    return bit;
}
