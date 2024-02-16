/*
** EPITECH PROJECT, 2023
** network_send_position.c
** File description:
** network_send_position.c
*/

#include "network.h"

int8_t network_send_position(int8_t line, int8_t column)
{
    int8_t byte = line % 8 + ((column % 8) << 3);

    return network_send_byte(byte);
}
