/*
** EPITECH PROJECT, 2023
** network_peer.c
** File description:
** network_peer.c
*/

#include "network.h"

void network_peer(network_operation_t operation, pid_t *pid)
{
    static pid_t peer = -1;

    if (operation == GET)
        *pid = peer;
    if (operation == SET)
        peer = *pid;
}
