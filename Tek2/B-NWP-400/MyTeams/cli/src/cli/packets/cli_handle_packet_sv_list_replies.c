/*
** EPITECH PROJECT, 2024
** cli_handle_packet_sv_list_replies.c
** File description:
** cli_handle_packet_sv_list_replies.c
*/

#include "cli.h"

#include "myteams/logging_client.h"

void cli_handle_packet_sv_list_replies(
    __attribute__((unused)) cli_t *self,
    sv_list_replies_packet_t *packet
)
{
    reply_t *reply;

    for (size_t i = 0; i < VEC_LEN(packet->replies); i++) {
        reply = *(reply_t **)VEC_AT(packet->replies, i);
        client_thread_print_replies(
            STRING_CDATA(reply->thread_uuid),
            STRING_CDATA(reply->user_uuid),
            reply->timestamp,
            STRING_CDATA(reply->body)
        );
    }
}
