/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** Implementation of my_put_nbr
*/

extern void my_putchar(char c);

static int compute_absolute_value(int n)
{
    return n < 0 ? -n : n;
}

int my_put_nbr(int nb)
{
    if (nb < 0)
        my_putchar('-');
    if (nb >= -9 && nb <= 9) {
        my_putchar('0' + compute_absolute_value(nb));
    } else {
        my_put_nbr(compute_absolute_value(nb / 10));
        my_putchar('0' + compute_absolute_value(nb % 10));
    }
    return 0;
}
