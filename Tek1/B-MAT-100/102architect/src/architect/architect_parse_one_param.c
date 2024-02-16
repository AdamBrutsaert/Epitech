/*
** EPITECH PROJECT, 2022
** architect_parse_one_param.c
** File description:
** architect_parse_one_param.c
*/

#include "architect.h"
#include <stdlib.h>

static int8_t is_number(char *string)
{
    if (*string == '-' || *string == '+')
        string++;
    for (; *string; string++)
        if (!(*string >= '0' && *string <= '9'))
            return 0;
    return 1;
}

int8_t architect_parse_one_param(int *argc, char ***argv, float *param1)
{
    if (*argc == 0)
        return 84;
    if (!is_number((*argv)[0]))
        return 84;
    *param1 = atof((*argv)[0]);
    (*argc)--;
    (*argv)++;
    return 0;
}
