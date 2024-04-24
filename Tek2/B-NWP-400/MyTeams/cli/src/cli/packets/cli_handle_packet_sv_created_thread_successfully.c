/*
** EPITECH PROJECT, 2024
** cli_handle_packet_sv_created_thread_successfully.c
** File description:
** cli_handle_packet_sv_created_thread_successfully.c
*/

#include "cli.h"

#include "myteams/logging_client.h"

void cli_handle_packet_sv_created_thread_successfully(
    __attribute__((unused)) cli_t *self,
    sv_created_thread_successfully_packet_t *packet
)
{
    client_print_thread_created(
        STRING_CDATA(packet->thread->uuid),
        STRING_CDATA(packet->thread->user_uuid),
        packet->thread->timestamp,
        STRING_CDATA(packet->thread->title),
        STRING_CDATA(packet->thread->body)
    );
}
