/*
** EPITECH PROJECT, 2022
** my_is_prime
** File description:
** Implementation of my_is_prime
*/

static int compute_upper_square_root(int nb)
{
    int square_root = 0;

    while (square_root * square_root < nb)
        square_root++;
    return square_root;
}

int my_is_prime(int nb)
{
    int upper_square_root = compute_upper_square_root(nb);

    if (nb < 2)
        return 0;
    if (nb == 2)
        return 1;
    for (int i = 2; i <= upper_square_root; i++) {
        if (nb % i == 0)
            return 0;
    }
    return 1;
}
