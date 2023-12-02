/*
** EPITECH PROJECT, 2022
** convert_base
** File description:
** Implementation of convert_base
*/

#include <stdlib.h>
#include "my.h"

static int get_abs(int n)
{
    return n < 0 ? -n : n;
}

static unsigned int get_digit_count_base(int nbr, char const *base)
{
    int length = my_strlen(base);
    unsigned int count = 1;

    while (nbr <= -length || nbr >= length) {
        nbr /= length;
        count++;
    }
    return count;
}

static void stringify(int nbr, char const *base, char *str)
{
    int length = my_strlen(base);
    int digit_count = get_digit_count_base(nbr, base);

    if (nbr < 0) {
        str[0] = '-';
        str++;
    }
    if (nbr > -length && nbr < length) {
        *str = base[get_abs(nbr)];
    } else {
        stringify(get_abs(nbr / length), base, str);
        str[digit_count - 1] = base[get_abs(nbr % length)];
    }
}

char *convert_base(char const *nbr, char const *base_from, char const *base_to)
{
    int nb = my_getnbr_base(nbr, base_from);
    unsigned int digits = get_digit_count_base(nb, base_to);
    char *str = malloc(sizeof(char) * ((nb < 0) + digits + 1));

    str[(nb < 0) + digits] = '\0';
    stringify(nb, base_to, str);
    return str;
}
