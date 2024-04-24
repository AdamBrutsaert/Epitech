/*
** EPITECH PROJECT, 2024
** server_run_from_args.c
** File description:
** server_run_from_args.c
*/

#include "ftp/server.h"
#include "utils/parsing.h"

#include <stdio.h>
#include <string.h>

static bool args_contains_help(int argc, char **argv)
{
    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "-help"))
            return true;
    }
    return false;
}

static void print_help(const char *program)
{
    printf("USAGE: %s port path\n", program);
    printf("\tport\tis the port number on which the server socket listens\n");
    printf(
        "\tpath\tis the path to the home directory for the Anonymous user\n"
    );
}

static bool create_server(server_t *server, int argc, char **argv)
{
    path_t path;
    uint16_t port;

    if (argc != 3 || !parse_port(&port, argv[1])
        || !path_init(&path, argv[2])) {
        print_help(argv[0]);
        return false;
    }
    if (!server_init(server, &(ipv4_address_t){0, port}, &path)) {
        path_deinit(&path);
        return false;
    }
    return true;
}

int server_run_from_args(int argc, char **argv)
{
    server_t server;
    bool status;

    if (args_contains_help(argc, argv)) {
        print_help(argv[0]);
        return 0;
    }
    if (!create_server(&server, argc, argv))
        return 84;
    status = server_run(&server);
    server_deinit(&server);
    return !status * 84;
}
