/*
** EPITECH PROJECT, 2022
** my_putnbr_base_precision
** File description:
** Implementation of my_putnbr_base_precision
*/

#include "my.h"

void my_putnbr_base_precision(intmax_t nbr, int precision, char const *base)
{
    int length = my_strlen(base);

    if (precision <= 0 && !nbr)
        return;
    if (nbr <= -length || nbr >= length || precision)
        my_putnbr_base_precision(my_abs(nbr / length), precision - 1, base);
    my_putchar(base[my_abs(nbr % length)]);
}

void my_putunbr_base_precision(uintmax_t nbr, int precision, char const *base)
{
    uintmax_t length = (uintmax_t)my_strlen(base);

    if (precision <= 0 && !nbr)
        return;
    if (nbr >= length || precision)
        my_putnbr_base_precision(my_abs(nbr / length), precision - 1, base);
    my_putchar(base[my_abs(nbr % length)]);
}
