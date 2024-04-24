/*
** EPITECH PROJECT, 2024
** cli_handle_packet_sv_disconnection_success.c
** File description:
** cli_handle_packet_sv_disconnection_success.c
*/

#include "cli.h"

void cli_handle_packet_sv_disconnection_success(
    cli_t *self,
    __attribute__((unused)) sv_disconnection_success_packet_t *packet
)
{
    self->running = false;
}
