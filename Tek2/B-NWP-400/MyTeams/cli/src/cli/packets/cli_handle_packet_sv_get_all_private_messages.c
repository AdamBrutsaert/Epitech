/*
** EPITECH PROJECT, 2024
** cli_handle_packet_sv_get_all_private_messages.c
** File description:
** cli_handle_packet_sv_get_all_private_messages.c
*/

#include "cli.h"

#include "protocol/entities/message.h"
#include "myteams/logging_client.h"

void cli_handle_packet_sv_get_all_private_messages(
    __attribute__((unused)) cli_t *self,
    sv_get_all_private_messages_packet_t *packet
)
{
    message_t *message;

    for (size_t i = 0; i < VEC_LEN(packet->messages); i++) {
        message = *(message_t **)VEC_AT(packet->messages, i);
        client_private_message_print_messages(
            STRING_CDATA(message->from_uuid),
            message->timestamp,
            STRING_CDATA(message->message)
        );
    }
}
