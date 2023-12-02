/*
** EPITECH PROJECT, 2022
** architect_parse_transformation.c
** File description:
** architect_parse_transformation.c
*/

#include "architect.h"
#include <string.h>

int8_t architect_parse_transformation(architect_context_t *ctx, int *argc,
    char ***argv)
{
    (*argc)--;
    (*argv)++;
    if (!strcmp((*argv - 1)[0], "-t"))
        return architect_parse_translation(ctx, argc, argv);
    if (!strcmp((*argv - 1)[0], "-z"))
        return architect_parse_scale(ctx, argc, argv);
    if (!strcmp((*argv - 1)[0], "-r"))
        return architect_parse_rotation(ctx, argc, argv);
    if (!strcmp((*argv - 1)[0], "-s"))
        return architect_parse_reflection(ctx, argc, argv);
    return 84;
}
