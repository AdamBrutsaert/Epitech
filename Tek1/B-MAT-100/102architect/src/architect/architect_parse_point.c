/*
** EPITECH PROJECT, 2022
** architect_parse_point.c
** File description:
** architect_parse_point.c
*/

#include "architect.h"
#include <stdlib.h>

static int8_t is_number(char *string)
{
    if (*string == '-' || *string == '+')
        string++;
    for (; *string; string++) {
        if (!(*string >= '0' && *string <= '9'))
            return 0;
    }
    return 1;
}

int8_t architect_parse_point(architect_context_t *ctx, int *argc, char ***argv)
{
    if (*argc < 2)
        return 84;
    if (!is_number((*argv)[0]) || !is_number((*argv)[1]))
        return 84;
    ctx->point = matrix_create_2d_point(atof((*argv)[0]), atof((*argv)[1]));
    *argc -= 2;
    *argv += 2;
    return 0;
}
