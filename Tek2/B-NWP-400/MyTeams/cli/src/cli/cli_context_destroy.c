/*
** EPITECH PROJECT, 2024
** MyTeams
** File description:
** cli_context_destroy
*/

#include "cli.h"

#include "my/memory/allocation.h"

void cli_context_destroy(cli_t *self)
{
    if (self->context_channel_uuid != nullptr)
        string_destroy(self->context_channel_uuid);
    if (self->context_team_uuid != nullptr)
        string_destroy(self->context_team_uuid);
    if (self->context_thread_uuid != nullptr)
        string_destroy(self->context_thread_uuid);
}
