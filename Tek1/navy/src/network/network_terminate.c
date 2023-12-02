/*
** EPITECH PROJECT, 2023
** network_terminate.c
** File description:
** network_terminate.c
*/

#include "network.h"

#include <stddef.h>

void network_terminate(void)
{
    network_buffer(DESTROY, NULL);
}
