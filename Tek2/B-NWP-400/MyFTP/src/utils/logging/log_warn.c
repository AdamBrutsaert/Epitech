/*
** EPITECH PROJECT, 2024
** log_warn.c
** File description:
** log_warn.c
*/

#include "utils/logging.h"

void log_warn(const char *format, ...)
{
    va_list args;

    log_begin(LOG_WARN);
    va_start(args, format);
    log_msg_va(format, args);
    va_end(args);
    log_end();
}
