/*
** EPITECH PROJECT, 2024
** log_msg_va.c
** File description:
** log_msg_va.c
*/

#include "utils/logging.h"

#include <stdio.h>

void log_msg_va(const char *format, va_list args)
{
    vprintf(format, args);
}
