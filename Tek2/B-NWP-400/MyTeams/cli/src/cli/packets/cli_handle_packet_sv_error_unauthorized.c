/*
** EPITECH PROJECT, 2024
** cli_handle_packet_sv_error_unauthorized.c
** File description:
** cli_handle_packet_sv_error_unauthorized.c
*/

#include "cli.h"

#include "myteams/logging_client.h"

void cli_handle_packet_sv_error_unauthorized(
    __attribute__((unused)) cli_t *self,
    __attribute__((unused)) sv_error_unauthorized_packet_t *packet
)
{
    client_error_unauthorized();
}
