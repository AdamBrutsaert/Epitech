/*
** EPITECH PROJECT, 2022
** my_compute_square_root
** File description:
** Implementation of my_compute_square_root
*/

int my_compute_square_root(int nb)
{
    int square_root = 0;

    while (square_root * square_root < nb)
        square_root++;
    if (square_root * square_root != nb)
        return 0;
    return square_root;
}
