/*
** EPITECH PROJECT, 2024
** command_parse.c
** File description:
** command_parse.c
*/

#include "ftp/command.h"

#include <string.h>

static const command_t commands[] = {
    { "NOOP", command_noop },
    { "USER", command_user },
    { "PASS", command_pass },
    { "HELP", command_help },
    { "QUIT", command_quit },
    { "PWD", command_pwd },
    { "CDUP", command_cdup },
    { "CWD", command_cwd },
    { "PORT", command_port },
    { "PASV", command_pasv },
    { "LIST", command_list },
    { "DELE", command_dele },
    { "STOR", command_stor },
    { "RETR", command_retr },
};

command_handler_t command_parse(char **args)
{
    if (args[0] == NULL)
        return command_unknown;
    for (size_t i = 0; i < sizeof(commands) / sizeof(command_t); i++) {
        if (strcmp(args[0], commands[i].name) == 0)
            return commands[i].handler;
    }
    return command_unknown;
}
