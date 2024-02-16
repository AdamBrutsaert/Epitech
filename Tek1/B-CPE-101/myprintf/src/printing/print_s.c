/*
** EPITECH PROJECT, 2022
** print_s
** File description:
** Implementation of print_s
*/

#include "printing/printing.h"
#include "my.h"
#include <unistd.h>

int print_s(format_t *format)
{
    char const *str = format->value->as_string;
    int str_length = my_strlen(str);
    int length = 0;

    if (format->precision >= 0)
        str_length = my_min(format->precision, str_length);
    if (!(format->flags & FLAG_LEFT_ADJUSTED))
        length += my_putnchar(' ', format->width - str_length);
    write(STDOUT_FILENO, str, str_length);
    if (format->flags & FLAG_LEFT_ADJUSTED)
        length += my_putnchar(' ', format->width - str_length);
    return length + str_length;
}
