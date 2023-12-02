/*
** EPITECH PROJECT, 2022
** print_ls.c
** File description:
** Implementation of print_ls.c
*/

#include "printing/printing.h"
#include "my.h"
#include <unistd.h>

static int my_wstrlen(wchar_t const *str)
{
    int length = 0;

    while (str[length])
        length++;
    return length;
}

static void my_putnwstr(wchar_t const *str, int n)
{
    for (int i = 0; i < n; i++)
        write(STDOUT_FILENO, &str[i], 1);
}

int print_ls(format_t *format)
{
    wchar_t const *str = format->value->as_wstring;
    int str_length = my_wstrlen(str);
    int length = 0;

    if (format->precision >= 0)
        str_length = my_min(format->precision, str_length);
    if (!(format->flags & FLAG_LEFT_ADJUSTED))
        length += my_putnchar(' ', format->width - str_length);
    my_putnwstr(str, str_length);
    if (format->flags & FLAG_LEFT_ADJUSTED)
        length += my_putnchar(' ', format->width - str_length);
    return length + str_length;
}
