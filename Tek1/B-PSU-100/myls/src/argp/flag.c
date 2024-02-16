/*
** EPITECH PROJECT, 2022
** flag.c
** File description:
** flag.c
*/

#include "my/details/argp.h"

int8_t is_short_flag(char const *arg)
{
    return *arg == '-' && arg[1] != '-';
}

int8_t is_long_flag(char const *arg)
{
    return *arg == '-' && arg[1] == '-';
}

int8_t is_flag(char const *arg)
{
    return is_short_flag(arg) || is_long_flag(arg);
}

int8_t is_stop_flag(char const *arg)
{
    return *arg == '-' && arg[1] == '-' && arg[2] == '\0';
}
