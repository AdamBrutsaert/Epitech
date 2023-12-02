/*
** EPITECH PROJECT, 2022
** print_s_maj.c
** File description:
** Implementation of print_s_maj.c
*/

#include "printing/printing.h"
#include "my.h"

static int print_non_printable(char c)
{
    my_putchar('\\');
    if (c < 8)
        my_putchar('0');
    if (c < 64)
        my_putchar('0');
    my_putnbr_base((int)c, "01234567");
    return 4;
}

static int print_printable(char const *str, int n)
{
    int length = 0;
    unsigned char character;

    for (int i = 0; i < n; i++) {
        character = (unsigned char)str[i];
        if (character < 32 || character >= 127) {
            length += print_non_printable(character);
        } else {
            my_putchar(character);
            length += 1;
        }
    }
    return length;
}

int print_s_maj(format_t *format)
{
    char const *str = format->value->as_string;
    int str_length = my_strlen(str);
    int length = 0;

    if (format->precision >= 0)
        str_length = my_min(format->precision, str_length);
    if (!(format->flags & FLAG_LEFT_ADJUSTED))
        length += my_putnchar(' ', format->width - str_length);
    length += print_printable(str, str_length);
    if (format->flags & FLAG_LEFT_ADJUSTED)
        length += my_putnchar(' ', format->width - str_length);
    return length;
}
