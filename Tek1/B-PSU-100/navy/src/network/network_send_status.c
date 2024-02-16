/*
** EPITECH PROJECT, 2023
** network_send_status.c
** File description:
** network_send_status.c
*/

#include "network.h"

int8_t network_send_status(int8_t status)
{
    return network_send_byte(status);
}
