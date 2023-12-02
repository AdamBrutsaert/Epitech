/*
** EPITECH PROJECT, 2023
** navy_from_arguments.c
** File description:
** navy_from_arguments.c
*/

#include "my.h"
#include "navy.h"
#include "network.h"

#include <unistd.h>

static int8_t establish_connection(navy_t *navy, int argc, char **argv)
{
    my_puts("my_pid: ");
    my_puti(getpid());
    my_putc('\n');
    if (argc == 3) {
        if (network_connect(str_to_pid(argv[1]), BIT_0) == 84)
            return 84;
        my_puts("successfully connected\n\n");
        navy->first = OPPONENT;
    } else {
        my_puts("waiting for enemy connection...\n");
        if (network_listen() == 84)
            return 84;
        my_puts("\nenemy connected\n\n");
        navy->first = SELF;
    }
    return 0;
}

static int8_t check_arguments(int argc, char **argv)
{
    if (argc != 2 && argc != 3)
        return 84;
    if (argc == 3 && !is_pid(argv[1]))
        return 84;
    return 0;
}

static int8_t destroy_and_return_error(navy_t *navy, char **argv, int8_t send)
{
    navy_destroy(navy);
    if (argv[2] != 0 && send)
        network_connect(str_to_pid(argv[1]), BIT_1);
    network_terminate();
    return 84;
}

int8_t navy_from_arguments(int argc, char **argv)
{
    navy_t *navy = navy_create();
    int8_t result;

    if (!navy)
        return 84;
    if (argc == 2 && !my_strcmp(argv[1], "-h")) {
        navy_help(argv[0]);
        return 0;
    }
    network_initialize();
    if (check_arguments(argc, argv) == 84)
        return destroy_and_return_error(navy, argv, 0);
    if (navy_parse_file(navy, argv[argc - 1]) == 84)
        return destroy_and_return_error(navy, argv, 1);
    if (establish_connection(navy, argc, argv) == 84)
        return destroy_and_return_error(navy, argv, 0);
    result = navy_run(navy);
    navy_destroy(navy);
    network_terminate();
    return result;
}
