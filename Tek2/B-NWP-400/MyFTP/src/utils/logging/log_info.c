/*
** EPITECH PROJECT, 2024
** log_info.c
** File description:
** log_info.c
*/

#include "utils/logging.h"

void log_info(const char *format, ...)
{
    va_list args;

    log_begin(LOG_INFO);
    va_start(args, format);
    log_msg_va(format, args);
    va_end(args);
    log_end();
}
