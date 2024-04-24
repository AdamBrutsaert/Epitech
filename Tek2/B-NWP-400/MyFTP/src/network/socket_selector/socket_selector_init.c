/*
** EPITECH PROJECT, 2024
** socket_selector_init.c
** File description:
** socket_selector_init.c
*/

#include "network/socket_selector.h"

void socket_selector_init(socket_selector_t *selector)
{
    selector->max_fd = 0;
    FD_ZERO(&selector->read_fds);
    FD_ZERO(&selector->write_fds);
    FD_ZERO(&selector->read_ready_fds);
    FD_ZERO(&selector->write_ready_fds);
}
