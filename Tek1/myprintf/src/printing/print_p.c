/*
** EPITECH PROJECT, 2022
** print_p.c
** File description:
** Implementation of print_p.c
*/

#include <unistd.h>
#include "my.h"
#include "printing/printing.h"

static int get_characters_count(uintmax_t nbr, int precision, uint8_t flags)
{
    int character = 2 + (nbr == 0) + (flags & FLAG_SIGN || flags & FLAG_BLANK);

    if (nbr == 0)
        return 5;
    for (; nbr; nbr /= 16)
        character++;
    return my_max(character, precision);
}

static void print_before_p(format_t *format, int width, int *length)
{
    if (!(format->flags & FLAG_LEFT_ADJUSTED)
        && !(format->flags & FLAG_ZERO_PADDED && format->precision == -1))
        *length += my_putnchar(' ', width - *length);
    if (!(format->flags & FLAG_LEFT_ADJUSTED)
        && format->flags & FLAG_ZERO_PADDED && format->precision == -1)
        *length += my_putnchar('0', width - *length);
    if (format->flags & FLAG_SIGN && format->value->as_pointer)
        my_putchar('+');
    if (!(format->flags & FLAG_SIGN) && format->flags & FLAG_BLANK
        && format->value->as_pointer)
        my_putchar(' ');
    if (format->value->as_pointer) {
        my_putchar('0');
        my_putchar('x');
    }
}

int print_p(format_t *format)
{
    int length = 0;
    int width = 0;
    int precision = format->precision <= 0 ? 1 : format->precision;

    length += get_characters_count((uintmax_t) format->value->as_pointer,
        format->precision, format->flags);
    width = my_max(length, format->width);
    print_before_p(format, width, &length);
    if (format->value->as_pointer) {
        my_putunbr_base_precision((uintmax_t) format->value->as_pointer,
            precision, "0123456789abcdef");
    } else {
        write(STDOUT_FILENO, "(nil)", 5);
        length += 5;
    }
    if (format->flags & FLAG_LEFT_ADJUSTED)
        length += my_putnchar(' ', width - length);
    return length;
}
