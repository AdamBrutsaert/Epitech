/*
** EPITECH PROJECT, 2022
** my_find_prime_sup
** File description:
** Implementation of my_find_prime_sup
*/

extern int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    int next = nb;

    if (nb <= 2)
        return 2;
    while (!my_is_prime(next))
        next++;
    return next;
}
