/*
** EPITECH PROJECT, 2024
** cli_handle_packet_sv_get_channel_info.c
** File description:
** cli_handle_packet_sv_get_channel_info.c
*/

#include "cli.h"

#include "myteams/logging_client.h"

void cli_handle_packet_sv_get_channel_info(
    __attribute__((unused)) cli_t *self,
    sv_get_channel_info_packet_t *packet
)
{
    client_print_channel(
        STRING_CDATA(packet->channel->uuid),
        STRING_CDATA(packet->channel->name),
        STRING_CDATA(packet->channel->description)
    );
}
