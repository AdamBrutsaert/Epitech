/*
** EPITECH PROJECT, 2022
** print_ap_int
** File description:
** Implementation of print_ap_int
*/

#include "miniprintf.h"

static int my_abs(int a)
{
    return a < 0 ? -a : a;
}

static int my_put_nbr(int nbr)
{
    int letters = 0;

    if (nbr < 0) {
        my_putchar('-');
        letters++;
    }
    if (nbr < -9 || nbr > 9)
        letters += my_put_nbr(my_abs(nbr / 10));
    my_putchar('0' + my_abs(nbr % 10));
    return letters + 1;
}

int print_ap_int(va_list *ap)
{
    return my_put_nbr(va_arg(*ap, int));
}
