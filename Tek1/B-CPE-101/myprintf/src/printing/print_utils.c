/*
** EPITECH PROJECT, 2022
** print_utils.c
** File description:
** Implementation of print_utils
*/

#include "printing/printing.h"
#include "my.h"
#include <unistd.h>

int print_before(format_t *format, int width, int length)
{
    int len = 0;

    if (!(format->flags & FLAG_LEFT_ADJUSTED)
        && !(format->flags & FLAG_ZERO_PADDED && format->precision == -1))
        len += my_putnchar(' ', width - length);
    if (format->value->as_int_max >= 0) {
        if (format->flags & FLAG_SIGN)
            my_putchar('+');
        if (!(format->flags & FLAG_SIGN) && format->flags & FLAG_BLANK)
            my_putchar(' ');
    } else {
        my_putchar('-');
    }
    if (!(format->flags & FLAG_LEFT_ADJUSTED)
        && format->flags & FLAG_ZERO_PADDED && format->precision == -1)
        len += my_putnchar('0', width - length);
    return len;
}

int print_after(format_t *format, int width, int length)
{
    if (format->flags & FLAG_LEFT_ADJUSTED)
        return my_putnchar(' ', width - length);
    return 0;
}

int print_unsigned_before(format_t *format, int width, int length, char *pre)
{
    int len = 0;

    if (!(format->flags & FLAG_LEFT_ADJUSTED)
        && !(format->flags & FLAG_ZERO_PADDED && format->precision == -1))
        len += my_putnchar(' ', width - length);
    if (format->flags & FLAG_SIGN)
        my_putchar('+');
    if (!(format->flags & FLAG_SIGN) && format->flags & FLAG_BLANK)
        my_putchar(' ');
    if (!(format->flags & FLAG_LEFT_ADJUSTED)
        && format->flags & FLAG_ZERO_PADDED && format->precision == -1)
        len += my_putnchar('0', width - length);
    if (format->flags & FLAG_ALTERNATE_FORM && pre)
        write(STDOUT_FILENO, pre, my_strlen(pre));
    return len;
}

int print_float_before(format_t *format, int width, int length)
{
    int len = 0;

    if (!(format->flags & FLAG_LEFT_ADJUSTED)
        && !(format->flags & FLAG_ZERO_PADDED && format->precision == -1))
        len += my_putnchar(' ', width - length);
    if (format->value->as_long_double >= 0) {
        if (format->flags & FLAG_SIGN)
            my_putchar('+');
        if (!(format->flags & FLAG_SIGN) && format->flags & FLAG_BLANK)
            my_putchar(' ');
    } else {
        my_putchar('-');
    }
    if (!(format->flags & FLAG_LEFT_ADJUSTED)
        && format->flags & FLAG_ZERO_PADDED && format->precision == -1)
        len += my_putnchar('0', width - length);
    return len;
}
