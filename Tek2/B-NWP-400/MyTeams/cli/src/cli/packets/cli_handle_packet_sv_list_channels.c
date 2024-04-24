/*
** EPITECH PROJECT, 2024
** cli_handle_packet_sv_list_channels.c
** File description:
** cli_handle_packet_sv_list_channels.c
*/

#include "cli.h"

#include "myteams/logging_client.h"

void cli_handle_packet_sv_list_channels(
    __attribute__((unused)) cli_t *self,
    sv_list_channels_packet_t *packet
)
{
    channel_t *channel;

    for (size_t i = 0; i < VEC_LEN(packet->channels); i++) {
        channel = *(channel_t **)VEC_AT(packet->channels, i);
        client_team_print_channels(
            STRING_CDATA(channel->uuid),
            STRING_CDATA(channel->name),
            STRING_CDATA(channel->description)
        );
    }
}
