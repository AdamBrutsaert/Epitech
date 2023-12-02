/*
** EPITECH PROJECT, 2023
** network_send_byte.c
** File description:
** network_send_byte.c
*/

#include "network.h"

#include <unistd.h>

int8_t network_send_byte(int8_t byte)
{
    for (uint8_t i = 0; i < 8; i++) {
        if (network_send_bit(byte & (1 << i)) == 84)
            return 84;
        usleep(10000);
    }
    return 0;
}
