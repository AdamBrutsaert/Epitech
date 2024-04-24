/*
** EPITECH PROJECT, 2024
** cli_handle_packet_sv_created_channel_successfully.c
** File description:
** cli_handle_packet_sv_created_channel_successfully.c
*/

#include "cli.h"

#include "myteams/logging_client.h"

void cli_handle_packet_sv_created_channel_successfully(
    __attribute__((unused)) cli_t *self,
    sv_created_channel_successfully_packet_t *packet
)
{
    client_print_channel_created(
        STRING_CDATA(packet->channel->uuid),
        STRING_CDATA(packet->channel->name),
        STRING_CDATA(packet->channel->description)
    );
}
