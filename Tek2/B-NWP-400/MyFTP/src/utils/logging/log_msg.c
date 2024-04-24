/*
** EPITECH PROJECT, 2024
** log_msg.c
** File description:
** log_msg.c
*/

#include "utils/logging.h"

void log_msg(const char *format, ...)
{
    va_list args;

    va_start(args, format);
    log_msg_va(format, args);
    va_end(args);
}
