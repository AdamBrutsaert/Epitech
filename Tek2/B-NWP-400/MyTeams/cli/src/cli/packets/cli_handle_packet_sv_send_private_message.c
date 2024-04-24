/*
** EPITECH PROJECT, 2024
** cli_handle_packet_sv_send_private_message.c
** File description:
** cli_handle_packet_sv_send_private_message.c
*/

#include "cli.h"
#include "myteams/logging_client.h"

void cli_handle_packet_sv_send_private_message(
    __attribute__((unused)) cli_t *self,
    sv_send_private_message_packet_t *packet
)
{
    client_event_private_message_received(
        STRING_DATA(packet->from_uuid),
        STRING_CDATA(packet->message)
    );
}
