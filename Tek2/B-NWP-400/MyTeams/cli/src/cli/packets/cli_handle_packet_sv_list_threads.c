/*
** EPITECH PROJECT, 2024
** cli_handle_packet_sv_list_threads.c
** File description:
** cli_handle_packet_sv_list_threads.c
*/

#include "cli.h"

#include "myteams/logging_client.h"

void cli_handle_packet_sv_list_threads(
    __attribute__((unused)) cli_t *self,
    sv_list_threads_packet_t *packet
)
{
    thread_t *thread;

    for (size_t i = 0; i < VEC_LEN(packet->threads); i++) {
        thread = *(thread_t **)VEC_AT(packet->threads, i);
        client_channel_print_threads(
            STRING_CDATA(thread->uuid),
            STRING_CDATA(thread->user_uuid),
            thread->timestamp,
            STRING_CDATA(thread->title),
            STRING_CDATA(thread->body)
        );
    }
}
