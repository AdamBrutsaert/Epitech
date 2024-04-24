/*
** EPITECH PROJECT, 2024
** control_log_info.c
** File description:
** control_log_info.c
*/

#include "ftp/control.h"
#include "utils/logging.h"

void control_log_info(control_t *self, const char *format, ...)
{
    va_list args;

    log_begin(LOG_INFO);
    va_start(args, format);
    log_msg(
        "[control] [%d.%d.%d.%d:%d] ",
        (self->address.address >> 24) & 0xFF,
        (self->address.address >> 16) & 0xFF,
        (self->address.address >> 8) & 0xFF,
        self->address.address & 0xFF,
        self->address.port
    );
    log_msg_va(format, args);
    va_end(args);
    log_end();
}
