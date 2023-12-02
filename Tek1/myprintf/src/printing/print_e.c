/*
** EPITECH PROJECT, 2022
** print_e
** File description:
** Implementation of print_e
*/

#include <unistd.h>
#include "my.h"
#include "printing/printing.h"

static int get_characters_count(long double nbr, int precision, uint8_t flags)
{
    int count = 2;

    if (my_digit_count(get_exponent(nbr)) > 2)
        count = my_digit_count(get_exponent(nbr));
    count += 3;
    count += nbr < 0;
    count += (nbr >= 0 && (flags & FLAG_BLANK || flags & FLAG_SIGN));
    if (precision > 0)
        count += precision + 1;
    return count;
}

static void print_number(format_t *format, int precision)
{
    long double base = get_base(format->value->as_long_double, precision);
    intmax_t exponent = get_exponent(format->value->as_long_double);

    base = base < 0 ? -base : base;
    my_putchar('0' + (intmax_t) base % 10);
    if (precision > 0) {
        my_putchar('.');
        base -= (intmax_t) base % 10;
        my_putnbr_base_precision(
            base * my_pow(10, precision), precision, "0123456789");
    }
    my_putchar('e');
    my_putchar(exponent < 0 ? '-' : '+');
    my_putnbr_base_precision(exponent, 2, "0123456789");
}

int print_e(format_t *format)
{
    int precision = format->precision <= -1 ? 6 : format->precision;
    int length = get_characters_count(
        format->value->as_long_double, precision, format->flags);
    int width = my_max(length, format->width);

    length += print_float_before(format, width, length);
    print_number(format, precision);
    length += print_after(format, width, length);
    return length;
}
