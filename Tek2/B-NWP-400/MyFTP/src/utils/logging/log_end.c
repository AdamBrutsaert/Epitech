/*
** EPITECH PROJECT, 2024
** log_end.c
** File description:
** log_end.c
*/

#include "utils/logging.h"

#include <stdio.h>

void log_end(void)
{
    printf("\x1B[0m\n");
    fflush(stdout);
}
