/*
** EPITECH PROJECT, 2024
** cli_destroy.c
** File description:
** cli_destroy.c
*/

#include "cli.h"

#include "my/memory/allocation.h"

void cli_destroy(cli_t *self)
{
    if (self->socket != nullptr)
        socket_destroy(self->socket);
    if (self->stream != nullptr)
        stream_destroy(self->stream);
    cli_context_destroy(self);
    selector_destroy(self->selector);
    reader_destroy(self->reader);
    deallocate(self);
}
