/*
** EPITECH PROJECT, 2023
** network_receive_byte.c
** File description:
** network_receive_byte.c
*/

#include "network.h"

#include <unistd.h>

int8_t network_receive_byte(void)
{
    uint64_t length = 0;
    bit_t bit;
    int8_t byte = 0;

    while (length < 8) {
        pause();
        network_buffer(LENGTH, &length);
    }
    for (uint8_t i = 0; i < 8; i++) {
        network_buffer(POP, &bit);
        byte |= bit << (7 - i);
    }
    return byte;
}
