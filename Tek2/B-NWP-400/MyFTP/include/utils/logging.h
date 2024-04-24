/*
** EPITECH PROJECT, 2024
** logging.h
** File description:
** logging.h
*/

#pragma once

#include <stdarg.h>

/********************************** Logging **********************************/

typedef enum {
    LOG_INFO = 0,
    LOG_WARN,
    LOG_ERROR,
} log_level_t;

/// Begin a log message
void log_begin(log_level_t level);

/// End a log message
void log_end(void);

/// Logs a message
void log_msg(const char *format, ...);

/// Logs a message with a va_list
void log_msg_va(const char *format, va_list args);

/// Logs an info message
void log_info(const char *format, ...);

/// Logs a warning message
void log_warn(const char *format, ...);

/// Logs an error message
void log_error(const char *format, ...);

/*****************************************************************************/
