/*
** EPITECH PROJECT, 2024
** cli_handle_input.c
** File description:
** cli_handle_input.c
*/

#include "cli.h"
#include "parsing/parser.h"

#include <stdio.h>

static const command_handler_t HANDLERS[PACKET_TYPE_COUNT] = {
    { "login", cli_handle_command_login },
    { "logout", cli_handle_command_logout },
    { "send", cli_handle_command_send },
    { "messages", cli_handle_command_messages },
    { "user", cli_handle_get_user_command },
    { "help", cli_handle_command_help },
    { "users", cli_handle_command_get_all_users },
    { "subscribe", cli_handle_command_subscribe },
    { "unsubscribe", cli_handle_command_unsubscribe },
    { "subscribed", cli_handle_command_subscribed },
    { "use", cli_handle_command_use_context },
    { "create", cli_handle_command_create },
    { "list", cli_handle_command_list },
    { "info", cli_handle_command_info }
};

static void process_command(cli_t *self, command_t *command)
{
    for (size_t i = 0; i < PACKET_TYPE_COUNT; i++) {
        if (HANDLERS[i].cmd == nullptr || HANDLERS[i].handler == nullptr)
            continue;
        if (!string_compare_cstr(command->name, HANDLERS[i].cmd)) {
            HANDLERS[i].handler(self, command);
            return;
        }
    }
    printf("[cli] Unknown command: >%s<\n", STRING_CDATA(command->name));
}

void cli_handle_input(cli_t *self)
{
    command_t *command = command_create();

    if (!command_parse(command, self->reader)) {
        reader_clear_up_to_newline(self->reader);
        command_destroy(command);
        return;
    }
    reader_clear_up_to_cursor(self->reader);
    process_command(self, command);
    command_destroy(command);
}
