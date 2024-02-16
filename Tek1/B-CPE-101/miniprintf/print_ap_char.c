/*
** EPITECH PROJECT, 2022
** print_ap_char
** File description:
** Implementation of print_ap_char
*/

#include "miniprintf.h"

int print_ap_char(va_list *ap)
{
    my_putchar((char)va_arg(*ap, int));
    return 1;
}
