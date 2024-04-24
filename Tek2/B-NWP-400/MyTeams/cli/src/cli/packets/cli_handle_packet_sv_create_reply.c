/*
** EPITECH PROJECT, 2024
** cli_handle_packet_sv_create_reply.c
** File description:
** cli_handle_packet_sv_create_reply.c
*/

#include "cli.h"

#include "myteams/logging_client.h"

void cli_handle_packet_sv_create_reply(
    __attribute__((unused)) cli_t *cli,
    sv_create_reply_packet_t *packet
)
{
    client_event_thread_reply_received(
        STRING_CDATA(packet->team->uuid),
        STRING_CDATA(packet->reply->thread_uuid),
        STRING_CDATA(packet->reply->user_uuid),
        STRING_CDATA(packet->reply->body)
    );
}
