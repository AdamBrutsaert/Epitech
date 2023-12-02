/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** Implementation my_put_nbr
*/

#include "my.h"
#include <unistd.h>

static int my_abs(int nb)
{
    return nb < 0 ? -nb : nb;
}

static void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_put_nbr(int nbr)
{
    if (nbr < 0)
        my_putchar('-');
    if (nbr < -9 || nbr > 9)
        my_put_nbr(my_abs(nbr / 10));
    my_putchar('0' + my_abs(nbr % 10));
}
