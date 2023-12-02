/*
** EPITECH PROJECT, 2022
** miniprintf
** File description:
** Implementation of miniprintf
*/

#include "miniprintf.h"
#include <stdarg.h>

static int call_ap(char token, va_list *ap, int *error)
{
    for (unsigned int i = 0; ap_tokens[i]; i++) {
        if (ap_tokens[i] == token)
            return (*ap_functions[i])(ap);
    }
    *error = 1;
    return 0;
}

static int process(char const **ptr, va_list *ap, int *error)
{
    if (**ptr == '%') {
        while (*(++(*ptr)) == ' ');
        return call_ap(**ptr, ap, error);
    }
    my_putchar(**ptr);
    return 1;
}

int mini_printf(char const *format, ...)
{
    va_list ap;
    int letters = 0;
    int error = 0;

    va_start(ap, format);
    for (; *format; format++)
        letters += process(&format, &ap, &error);
    va_end(ap);
    return error ? -84 : letters;
}
