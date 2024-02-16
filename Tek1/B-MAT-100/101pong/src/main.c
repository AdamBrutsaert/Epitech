/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pong.h"

static int print_usage(char const *prog_name)
{
    puts("USAGE");
    printf("    %s x0 y0 z0 x1 y1 z1 n\n\n", prog_name);
    puts("DESCRIPTION");
    puts("    x0  ball abscissa at time t - 1");
    puts("    y0  ball ordinate at time t - 1");
    puts("    z0  ball altitude at time t - 1");
    puts("    x1  ball abscissa at time t");
    puts("    y1  ball ordinate at time t");
    puts("    z1  ball altitude at time t");
    puts("    n   time shift (greater than or equal to zero, integer)");
    return 0;
}

static int is_valid(char const *arg)
{
    char dot = 0;

    for (; *arg; arg++) {
        if ((*arg < '0' && *arg > '9' && *arg != '.') || (*arg == '.' && dot))
            return 0;
        if (*arg == '.')
            dot = 1;
    }
    return 1;
}

static int is_float(char const *arg)
{
    for (; *arg; arg++)
        if (*arg == '.')
            return 1;
    return 0;
}

static int are_parameters_valid(char **argv)
{
    return is_valid(argv[1]) && is_valid(argv[2]) && is_valid(argv[3])
        && is_valid(argv[4]) && is_valid(argv[5]) && is_valid(argv[6])
        && is_valid(argv[7]) && !is_float(argv[7]);
}

int main(int argc, char **argv)
{
    parameters_t parameters;

    for (int i = 1; i < argc; i++)
        if (!strcmp(argv[i], "-h"))
            return print_usage(argv[0]);
    if (argc != 8) {
        fputs("Error: invalid number of arguments\n", stderr);
        return 84;
    }
    if (!are_parameters_valid(argv))
        return 84;
    parameters.x0 = atof(argv[1]);
    parameters.y0 = atof(argv[2]);
    parameters.z0 = atof(argv[3]);
    parameters.x1 = atof(argv[4]);
    parameters.y1 = atof(argv[5]);
    parameters.z1 = atof(argv[6]);
    parameters.n = atoi(argv[7]);
    return pong(&parameters);
}
