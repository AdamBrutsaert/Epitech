/*
** EPITECH PROJECT, 2022
** print_u
** File description:
** Implementation of print_u
*/

#include "my.h"
#include "printing/printing.h"

static int get_characters_count(uintmax_t nbr, int precision)
{
    int count = my_unsigned_digit_count(nbr, 10);

    return !nbr && !precision ? 0 : my_max(count, precision);
}

static void remove_flags(format_t *format)
{
    uint8_t flags = 0;

    if (format->flags & FLAG_LEFT_ADJUSTED)
        flags |= FLAG_LEFT_ADJUSTED;
    if (format->flags & FLAG_ZERO_PADDED)
        flags |= FLAG_ZERO_PADDED;
    format->flags = flags;
}

int print_u(format_t *format)
{
    int precision = format->precision <= -1 ? 1 : format->precision;
    int length = get_characters_count(
        format->value->as_unsigned_int_max, precision);
    int width = my_max(length, format->width);

    remove_flags(format);
    length += print_unsigned_before(format, width, length, 0);
    my_putunbr_base_precision(
        format->value->as_unsigned_int_max, precision, "0123456789");
    length += print_after(format, width, length);
    return length;
}
