/*
** EPITECH PROJECT, 2022
** print_f_maj
** File description:
** Implementation of print_f_maj
*/

#include "printing/printing.h"
#include "my.h"

static int get_characters_count(long double nbr, int precision)
{
    int integer = my_digit_count((intmax_t) nbr);

    return integer + precision + (precision > 0);
}

static intmax_t get_decimals(format_t *format, int precision)
{
    intmax_t pow = my_pow(10, precision + 1);
    intmax_t decimals = (intmax_t) (format->value->as_long_double * pow) % pow;

    if (decimals % 10 >= 5)
        return decimals / 10 + 1;
    return decimals / 10;
}

int print_f_maj(format_t *format)
{
    int precision = format->precision <= -1 ? 6 : format->precision;
    int length =
        get_characters_count(format->value->as_long_double, precision);
    int width = my_max(length, format->width);

    length += print_float_before(format, width, length);
    my_putnbr_base((intmax_t) format->value->as_long_double, "0123456789");
    if (precision) {
        my_putchar('.');
        my_putnbr_base_precision(
            get_decimals(format, precision), precision, "0123456789");
    }
    length += print_after(format, width, length);
    return length;
}
