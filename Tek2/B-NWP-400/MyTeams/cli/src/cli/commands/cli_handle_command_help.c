/*
** EPITECH PROJECT, 2024
** cli_handle_command_help.c
** File description:
** cli_handle_command_help.c
*/

#include "cli.h"

#include <stdio.h>

static const char *message = ""
"\n\tMyTeams CLI - Copyright 2024 - Les deux poggers et l'autre\n"
"This is the official CLI, if you want to implement your own CLI, "
"you can use the RFC.\n\n"
"Here is a list of available commands:\n"
"\t• /login [“user_name”]: set the user_name used by client\n"
"\t• /logout: disconnect the client from the server\n"
"\t• /users: get the list of all users that exist on the domain\n"
"\t• /user [“user_uuid”]: get details about the requested user\n"
"\t• /send [“user_uuid”] [“message_body”]: send a message to the "
"user identified by user_uuid\n"
"\t• /messages [“user_uuid”]: list all messages exchange with an "
"user identified by user_uuid\n"
"\t• /subscribe [“team_uuid”]: subscribe to the events of a team "
"and its sub directories (enable reception of all events from a team)\n"
"\t• /subscribed ?[“team_uuid”]: list all subscribed teams or list "
"all users subscribed to a team\n"
"\t• /unsubscribe [“team_uuid”]: unsubscribe from a team\n"
"• /use ?[\"team_uuid\"]?[\"channel_uuid\"]?[\"thread_uuid\"]: Sets the "
"command context to a team/channel/thread\n\n"
"/create: based on the context, create the sub resource "
"(see below)\n\n"
"\tWhen the context is not defined (/use):\n"
"\t• /create [“team_name”] [“team_description”]: create a "
"new team\n\n"
"\tWhen team_uuid is defined (/use “team_uuid”):\n"
"\t• /create [“channel_name”] [“channel_description”]: create a "
"new channel\n\n"
"\tWhen team_uuid and channel_uuid are defined (/use “team_uuid” "
"“channel_uuid”):\n"
"\t• /create [“thread_title”] [“thread_message”]: create a new "
"thread\n\n"
"\tWhen team_uuid, channel_uuid and thread_uuid are defined "
"(/use “team_uuid” “channel_uuid” “thread_uuid”):\n"
"\t• /create [“comment_body”]: create a new reply\n\n"
"/list: based on the context, list all the sub resources "
"(see below)\n\n"
"\tWhen the context is not defined (/use):\n"
"\t• /list: list all existing teams\n\n"
"\tWhen team_uuid is defined (/use “team_uuid”):\n"
"\t• /list: list all existing channels\n\n"
"\tWhen team_uuid and channel_uuid are defined "
"(/use “team_uuid” “channel_uuid”):\n"
"\t• /list: list all existing threads\n\n"
"\tWhen team_uuid, channel_uuid and thread_uuid are defined "
"(/use “team_uuid” “channel_uuid” “thread_uuid”):\n"
"\t• /list: list all existing replies\n\n"
"/info: based on the context, display details of the current "
"resource (see below)\n\n"
"\tWhen the context is not defined (/use):\n"
"\t• /info: display currently logged-in user details\n\n"
"\tWhen team_uuid is defined (/use “team_uuid”):\n"
"\t• /info: display currently selected team details\n\n"
"\tWhen team_uuid and channel_uuid are defined "
"(/use “team_uuid” “channel_uuid”):\n"
"\t• /info: display currently selected channel details\n\n"
"\tWhen team_uuid, channel_uuid and thread_uuid are defined "
"(/use “team_uuid” “channel_uuid” “thread_uuid”):\n"
"\t• /info: display currently selected thread details\n\n"
"Point of attention:\n"
"• Please note that all arguments of the existing commands should "
"be quoted with double quotes.\n"
"• Max name length: 32\n"
"• Max description length: 255\n"
"• Max message length: 512\n\n"
"\t\t2024 - All rights reserved.\n";

void cli_handle_command_help(cli_t *self, command_t *cmd)
{
    (void)self;
    (void)cmd;
    printf("%s", message);
}
