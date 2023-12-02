/*
** EPITECH PROJECT, 2022
** architect_parse_args.c
** File description:
** architect_parse_args.c
*/

#include "architect.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void print_help(char *prog)
{
    printf("USAGE\n");
    printf("    %s x y transfo1 arg11 [arg12] [transfo2 arg21 [arg22]] ...\n\n",
        prog);
    printf("DESCRIPTION\n");
    printf("    x   abscissa of the original point\n");
    printf("    y   ordinate of the original point\n\n");
    printf("    transfo arg1 [arg2]\n");
    printf("    -t i j  translation along vector (i, j)\n");
    printf("    -z m n  scaling by factor m (x-axis) and n (y-axis)\n");
    printf("    -r d    rotation centered in O by a d degree angle\n");
    printf("    -s d    reflection over the axis passing through O with an "
        "inclination angle of d degrees\n");
    exit(0);
}

int8_t architect_parse_args(architect_context_t *ctx, int argc, char **argv)
{
    argc--;
    argv++;
    if (argc && !strcmp(argv[0], "-h"))
        print_help(*(argv - 1));
    if (architect_parse_point(ctx, &argc, &argv))
        return 84;
    if (!argc)
        return 84;
    while (argc)
        if (architect_parse_transformation(ctx, &argc, &argv))
            return 84;
    return 0;
}
