/*
** EPITECH PROJECT, 2022
** print_c
** File description:
** Implementation of print_c
*/

#include "printing/printing.h"
#include "my.h"

int print_c(format_t *format)
{
    int length = 0;

    if (!(format->flags & FLAG_LEFT_ADJUSTED))
        length += my_putnchar(' ', format->width - 1);
    my_putchar((unsigned char)format->value->as_int_max);
    if (format->flags & FLAG_LEFT_ADJUSTED)
        length += my_putnchar(' ', format->width - 1);
    return length + 1;
}
