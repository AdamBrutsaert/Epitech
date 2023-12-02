/*
** EPITECH PROJECT, 2022
** print_di
** File description:
** Implementation of print_di
*/

#include "my.h"
#include "printing/printing.h"

static int get_characters_count(intmax_t nbr, uint8_t flags, int precision)
{
    int count = my_digit_count(nbr);

    count += (nbr < 0);
    count += (nbr > 0 && (flags & FLAG_BLANK || flags & FLAG_SIGN));
    return !nbr && !precision ? 0 : my_max(count, precision);
}

int print_di(format_t *format)
{
    int precision = format->precision <= -1 ? 1 : format->precision;
    int length = get_characters_count(
        format->value->as_int_max, format->flags, precision);
    int width = my_max(length, format->width);

    length += print_before(format, width, length);
    my_putnbr_base_precision(
        format->value->as_int_max, precision, "0123456789");
    length += print_after(format, width, length);
    return length;
}
