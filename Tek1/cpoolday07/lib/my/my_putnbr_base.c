/*
** EPITECH PROJECT, 2022
** my_putnbr_base
** File description:
** Implementatino of my_putnbr_base
*/

extern void my_putchar(char c);
extern int my_strlen(char const *str);

static int compute_absolute_value(int n)
{
    return n < 0 ? -n : n;
}

int my_putnbr_base(int nbr, char const *base)
{
    int length = my_strlen(base);

    if (length < 2)
        return 0;
    if (nbr < 0)
        my_putchar('-');
    if (nbr > -length && nbr < length) {
        my_putchar(base[compute_absolute_value(nbr)]);
    } else {
        my_putnbr_base(compute_absolute_value(nbr / length), base);
        my_putchar(base[compute_absolute_value(nbr % length)]);
    }
    return 0;
}
