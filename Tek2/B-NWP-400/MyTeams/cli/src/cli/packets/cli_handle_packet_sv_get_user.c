/*
** EPITECH PROJECT, 2024
** cli_handle_packet_sv_get_user.c
** File description:
** cli_handle_packet_sv_get_user.c
*/

#include "cli.h"
#include "myteams/logging_client.h"

void cli_handle_packet_sv_get_user(
    __attribute__((unused)) cli_t *self,
    sv_get_user_packet_t *packet
)
{
    client_print_user(
        STRING_CDATA(packet->user->uuid),
        STRING_CDATA(packet->user->name),
        !!packet->user->connections
    );
}
