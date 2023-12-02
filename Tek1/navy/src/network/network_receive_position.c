/*
** EPITECH PROJECT, 2023
** network_receive_position.c
** File description:
** network_receive_position.c
*/

#include "network.h"

void network_receive_position(int8_t *line, int8_t *column)
{
    int8_t byte = network_receive_byte();

    *line = byte % 8;
    *column = (byte >> 3) % 8;
}
