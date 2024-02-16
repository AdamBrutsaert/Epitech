/*
** EPITECH PROJECT, 2022
** my_digit_count.c
** File description:
** Implementation of my_digit_count
*/

#include "my.h"

int my_digit_count(intmax_t a)
{
    int length = (a == 0);

    for (; a; a /= 10)
        length++;
    return length;
}

int my_unsigned_digit_count(uintmax_t a, uintmax_t base)
{
    int length = (a == 0);

    for (; a; a /= base)
        length++;
    return length;
}

intmax_t get_exponent(long double nbr)
{
    int exponent = 0;

    for (; nbr >= 10; nbr /= 10)
        exponent++;
    for (; (intmax_t) nbr % 10 == 0 && nbr; nbr *= 10)
        exponent--;
    return exponent;
}

long double get_base(long double nbr, int precision)
{
    nbr = nbr < 0 ? -nbr : nbr;
    while (nbr >= 10)
        nbr /= 10;
    while ((intmax_t) nbr % 10 == 0 && nbr)
        nbr *= 10;
    nbr *= my_pow(10, precision + 1);
    if ((intmax_t) nbr % 10 >= 5)
        nbr += 10;
    nbr /= my_pow(10, precision + 1);
    return nbr;
}
