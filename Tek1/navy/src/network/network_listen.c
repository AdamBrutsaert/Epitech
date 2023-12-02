/*
** EPITECH PROJECT, 2023
** network_listen.c
** File description:
** network_listen.c
*/

#include "network.h"

int8_t network_listen(void)
{
    return network_receive_bit() == BIT_0 ? 0 : 84;
}
