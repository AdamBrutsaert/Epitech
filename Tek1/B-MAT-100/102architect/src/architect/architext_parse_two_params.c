/*
** EPITECH PROJECT, 2022
** architext_parse_two_params.c
** File description:
** architext_parse_two_params.c
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

int8_t architect_parse_two_params(int *argc, char ***argv, float *param1,
    float *param2)
{
    if (*argc < 2)
        return 84;
    if (!is_number((*argv)[0]) || !is_number((*argv)[1]))
        return 84;
    *param1 = atof((*argv)[0]);
    *param2 = atof((*argv)[1]);
    *argc -= 2;
    *argv += 2;
    return 0;
}
