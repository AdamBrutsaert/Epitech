/*
** EPITECH PROJECT, 2022
** print_g
** File description:
** Implementation of print_g
*/

#include "my.h"
#include "printing/printing.h"

static int print_e_proxy(format_t *format)
{
    long double base =
        get_base(format->value->as_long_double, format->precision) + 1e-15;

    base = base * my_pow(10, format->precision - 1);
    for (; (intmax_t) base % 10 == 0; base /= 10)
        format->precision--;
    format->precision = my_max(format->precision - 1, 0);
    return print_e(format);
}

static int print_f_proxy(format_t *format)
{
    long double value = format->value->as_long_double + 1e-15;
    int precision = format->precision;

    if (format->value->as_long_double == 0) {
        format->precision = 0;
        return print_f(format);
    }
    if (value > -1 && value < 1) {
        for (value *= 10; (intmax_t) value == 0; value *= 10)
            precision++;
        value *= my_pow(10, format->precision - 1);
    } else {
        precision = my_max(precision - my_digit_count((intmax_t) value), 0);
        value *=
            my_pow(10, format->precision - my_digit_count((intmax_t) value));
    }
    for (; (intmax_t) value % 10 == 0; value /= 10)
        precision--;
    format->precision = precision;
    return print_f(format);
}

int print_g(format_t *format)
{
    intmax_t exponent = get_exponent(format->value->as_long_double);

    format->precision = (format->precision <= -1 ? 6 : format->precision)
        + (format->precision == 0);
    if (exponent < -4 || exponent >= format->precision)
        return print_e_proxy(format);
    return print_f_proxy(format);
}
