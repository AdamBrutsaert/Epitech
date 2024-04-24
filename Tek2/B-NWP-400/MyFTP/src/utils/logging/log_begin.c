/*
** EPITECH PROJECT, 2024
** log_begin.c
** File description:
** log_begin.c
*/

#include "utils/logging.h"

#include <stdio.h>

void log_begin(log_level_t level)
{
    switch (level) {
    case LOG_INFO:
        printf("\x1B[34m[INFO] ");
        break;
    case LOG_WARN:
        printf("\x1B[33m[WARNING] ");
        break;
    case LOG_ERROR:
        printf("\x1B[31m[ERROR] ");
        break;
    }
}
