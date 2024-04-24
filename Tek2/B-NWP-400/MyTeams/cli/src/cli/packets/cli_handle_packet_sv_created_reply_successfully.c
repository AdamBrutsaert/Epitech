/*
** EPITECH PROJECT, 2024
** cli_handle_packet_sv_created_reply_successfully.c
** File description:
** cli_handle_packet_sv_created_reply_successfully.c
*/

#include "cli.h"

#include "myteams/logging_client.h"

void cli_handle_packet_sv_created_reply_successfully(
    __attribute__((unused)) cli_t *self,
    sv_created_reply_successfully_packet_t *packet
)
{
    client_print_reply_created(
        STRING_CDATA(packet->reply->thread_uuid),
        STRING_CDATA(packet->reply->user_uuid),
        packet->reply->timestamp,
        STRING_CDATA(packet->reply->body)
    );
}
