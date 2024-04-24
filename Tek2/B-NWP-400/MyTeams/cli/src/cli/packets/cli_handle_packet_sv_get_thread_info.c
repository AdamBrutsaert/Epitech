/*
** EPITECH PROJECT, 2024
** cli_handle_packet_sv_get_thread_info.c
** File description:
** cli_handle_packet_sv_get_thread_info.c
*/

#include "cli.h"

#include "myteams/logging_client.h"

void cli_handle_packet_sv_get_thread_info(
    __attribute__((unused)) cli_t *self,
    sv_get_thread_info_packet_t *packet
)
{
    client_print_thread(
        STRING_CDATA(packet->thread->uuid),
        STRING_CDATA(packet->thread->user_uuid),
        packet->thread->timestamp,
        STRING_CDATA(packet->thread->title),
        STRING_CDATA(packet->thread->body)
    );
}
