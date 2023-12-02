/*
** EPITECH PROJECT, 2022
** my_compute_factorial_it
** File description:
** Implementation of my_compute_factorial_it
*/

int my_compute_factorial_it(int nb)
{
    int number = 1;

    if (nb < 0 || nb > 12)
        return 0;
    for (; nb; nb--)
        number *= nb;
    return number;
}
