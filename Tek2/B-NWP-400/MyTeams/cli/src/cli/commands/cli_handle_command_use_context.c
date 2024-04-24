/*
** EPITECH PROJECT, 2024
** cli_handle_command_login.c
** File description:
** cli_handle_command_login.c
*/

#include "cli.h"

#include <stdio.h>

static void assign_context(cli_t *self, command_t *cmd)
{
    self->context_team_uuid = nullptr;
    self->context_channel_uuid = nullptr;
    self->context_thread_uuid = nullptr;
    if (VEC_LEN(cmd->arguments) >= 1)
        self->context_team_uuid =
            string_clone(*(string_t **)VEC_AT(cmd->arguments, 0));
    if (VEC_LEN(cmd->arguments) >= 2)
        self->context_channel_uuid =
            string_clone(*(string_t **)VEC_AT(cmd->arguments, 1));
    if (VEC_LEN(cmd->arguments) >= 3)
        self->context_thread_uuid =
            string_clone(*(string_t **)VEC_AT(cmd->arguments, 2));
}

void cli_handle_command_use_context(cli_t *self, command_t *cmd)
{
    if (VEC_LEN(cmd->arguments) > 3) {
        printf("Usage: /use ?[\"team\"]?[\"channel\"]?[\"thread\"]\n");
        return;
    }
    cli_context_destroy(self);
    assign_context(self, cmd);
}
