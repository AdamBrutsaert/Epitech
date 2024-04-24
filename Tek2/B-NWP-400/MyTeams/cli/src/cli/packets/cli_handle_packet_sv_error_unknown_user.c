/*
** EPITECH PROJECT, 2024
** cli_handle_packet_sv_error_unknown_user.c
** File description:
** cli_handle_packet_sv_error_unknown_user.c
*/

#include "cli.h"

#include "myteams/logging_client.h"

void cli_handle_packet_sv_error_unknown_user(
    __attribute__((unused)) cli_t *self,
    sv_error_unknown_user_packet_t *packet
)
{
    client_error_unknown_user(STRING_CDATA(packet->uuid));
}
