/*
** EPITECH PROJECT, 2024
** server_run_from_args.c
** File description:
** server_run_from_args.c
*/

#include "server.h"

#include "my/memory/cstr.h"

#include <stdio.h>

static const char *HELP = ""
"USAGE:\t./myteams_server port\n"
"\n"
"\t\tport\tis the port number on which the server socket listens.\n";

static bool parse_arguments(int ac, char **av, uint16_t *port)
{
    if (ac != 2) {
        printf("%s", HELP);
        return false;
    }
    if (!cstr_to_u16(av[1], port) || *port < 1024) {
        printf("[cli] Invalid port\n");
        return false;
    }
    return true;
}

int server_run_from_args(int ac, char **av)
{
    ipv4_address_t address = {.address = {0, 0, 0, 0}};
    server_t *server;
    bool result;

    if (cstr_array_contains_help(av)) {
        printf("%s", HELP);
        return 0;
    }
    if (!parse_arguments(ac, av, &address.port))
        return 84;
    server = server_create();
    result = server_run(server, &address);
    server_destroy(server);
    return !result * 84;
}
