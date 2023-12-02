/*
** EPITECH PROJECT, 2022
** my_put_nbr_base
** File description:
** Implementation of my_put_nbr_base
*/

#include "my.h"
#include <unistd.h>

void my_putnbr_base(int nbr, char const *base)
{
    int length = (int)my_strlen(base);

    if (nbr <= -length || nbr >= length)
        my_putnbr_base(my_abs(nbr / length), base);
    my_putchar(base[my_abs(nbr % length)]);
}
