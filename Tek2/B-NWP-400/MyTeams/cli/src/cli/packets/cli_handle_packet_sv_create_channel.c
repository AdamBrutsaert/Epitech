/*
** EPITECH PROJECT, 2024
** cli_handle_packet_sv_create_channel.c
** File description:
** cli_handle_packet_sv_create_channel.c
*/

#include "cli.h"

#include "myteams/logging_client.h"

void cli_handle_packet_sv_create_channel(
    __attribute__((unused)) cli_t *self,
    sv_create_channel_packet_t *packet
)
{
    client_event_channel_created(
        STRING_CDATA(packet->channel->uuid),
        STRING_CDATA(packet->channel->name),
        STRING_CDATA(packet->channel->description)
    );
}
