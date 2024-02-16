/*
** EPITECH PROJECT, 2022
** print_o
** File description:
** Implementation of print_o
*/

#include "my.h"
#include "printing/printing.h"

static int get_characters_count(uintmax_t nbr, uint8_t flags, int precision)
{
    int count = my_unsigned_digit_count(nbr, 8);

    count += (flags & FLAG_ALTERNATE_FORM);
    return my_max(count, precision);
}

static void remove_flags(format_t *format)
{
    uint8_t flags = 0;

    if (format->flags & FLAG_LEFT_ADJUSTED)
        flags |= FLAG_LEFT_ADJUSTED;
    if (format->flags & FLAG_ZERO_PADDED)
        flags |= FLAG_ZERO_PADDED;
    if (format->flags & FLAG_ALTERNATE_FORM)
        flags |= FLAG_ALTERNATE_FORM;
    format->flags = flags;
}

int print_o(format_t *format)
{
    int precision = format->precision <= 0 ? 1 : format->precision;
    int length = get_characters_count(
        format->value->as_unsigned_int_max, format->flags, precision);
    int width = my_max(length, format->width);

    remove_flags(format);
    if (precision == length && format->flags & FLAG_ALTERNATE_FORM)
        precision -= 1;
    length += print_unsigned_before(format, width, length, "0");
    my_putunbr_base_precision(
        format->value->as_unsigned_int_max, precision, "01234567");
    length += print_after(format, width, length);
    return length;
}
