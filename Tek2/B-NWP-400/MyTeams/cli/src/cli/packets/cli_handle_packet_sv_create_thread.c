/*
** EPITECH PROJECT, 2024
** cli_handle_packet_sv_create_thread.c
** File description:
** cli_handle_packet_sv_create_thread.c
*/

#include "cli.h"

#include "myteams/logging_client.h"

void cli_handle_packet_sv_create_thread(
    __attribute__((unused)) cli_t *self,
    sv_create_thread_packet_t *packet
)
{
    client_event_thread_created(
        STRING_CDATA(packet->thread->uuid),
        STRING_CDATA(packet->thread->user_uuid),
        packet->thread->timestamp,
        STRING_CDATA(packet->thread->title),
        STRING_CDATA(packet->thread->body)
    );
}
