/*
** EPITECH PROJECT, 2024
** parse_port.c
** File description:
** parse_port.c
*/

#include "utils/parsing.h"

#include <stdlib.h>

static bool is_port(const char *string)
{
    for (; *string; string++) {
        if (*string < '0' || *string > '9')
            return false;
    }
    return true;
}

bool parse_port(uint16_t *port, const char *string)
{
    int value;

    if (!is_port(string))
        return false;
    value = atoi(string);
    if (value < 1024 || value > 65535)
        return false;
    *port = value;
    return value;
}
