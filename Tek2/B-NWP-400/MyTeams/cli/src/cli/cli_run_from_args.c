/*
** EPITECH PROJECT, 2024
** cli_run_from_args.c
** File description:
** cli_run_from_args.c
*/

#include "cli.h"

#include "my/memory/cstr.h"

#include <stdio.h>

static const char *HELP = ""
"USAGE:\t./myteams_cli ip port\n"
"\t\tip\t\tis the server ip address on which the server socket listens\n"
"\t\tport\tis the port number on which the server socket listens\n";

static bool parse_arguments(int ac, char **av, ipv4_address_t *address)
{
    if (ac != 3) {
        printf("%s", HELP);
        return false;
    }
    if (!cstr_to_ipv4_addr(av[1], (uint32_t *)&address->address)) {
        printf("[cli] Invalid IPv4 address\n");
        return false;
    }
    if (!cstr_to_u16(av[2], &address->port) || address->port < 1024) {
        printf("[cli] Invalid port\n");
        return false;
    }
    return true;
}

int cli_run_from_args(int ac, char **av)
{
    ipv4_address_t address;
    cli_t *cli;
    bool result;

    if (cstr_array_contains_help(av)) {
        printf("%s", HELP);
        return 0;
    }
    if (!parse_arguments(ac, av, &address))
        return 84;
    cli = cli_create();
    result = cli_run(cli, &address);
    cli_destroy(cli);
    return !result * 84;
}
