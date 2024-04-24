/*
** EPITECH PROJECT, 2024
** log_error.c
** File description:
** log_error.c
*/

#include "utils/logging.h"

void log_error(const char *format, ...)
{
    va_list args;

    log_begin(LOG_ERROR);
    va_start(args, format);
    log_msg_va(format, args);
    va_end(args);
    log_end();
}
