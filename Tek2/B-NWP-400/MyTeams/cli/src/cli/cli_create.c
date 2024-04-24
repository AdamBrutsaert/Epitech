/*
** EPITECH PROJECT, 2024
** cli_create.c
** File description:
** cli_create.c
*/

#include "cli.h"

#include "my/memory/allocation.h"

cli_t *cli_create(void)
{
    cli_t *self = allocate(sizeof(cli_t));

    self->socket = socket_create();
    self->stream = nullptr;
    self->selector = selector_create();
    self->reader = reader_create();
    self->running = true;
    self->context_channel_uuid = nullptr;
    self->context_team_uuid = nullptr;
    self->context_thread_uuid = nullptr;
    return self;
}
