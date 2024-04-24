/*
** EPITECH PROJECT, 2024
** cli_handle_packet_sv_user_logged_out.c
** File description:
** cli_handle_packet_sv_user_logged_out.c
*/

#include "cli.h"

#include "myteams/logging_client.h"

void cli_handle_packet_sv_user_logged_out(
    __attribute__((unused)) cli_t *self,
    sv_user_logged_out_packet_t *packet
)
{
    client_event_logged_out(
        STRING_CDATA(packet->uuid),
        STRING_CDATA(packet->name)
    );
}
