/*
** EPITECH PROJECT, 2022
** my_compute_power_rec
** File description:
** Implementation of my_compute_power_rec
*/

int my_compute_power_rec(int nb, int p)
{
    int temp;
    int number;

    if (p == 0)
        return 1;
    if (p == 1)
        return nb;
    if (p < 0 || (p && !nb))
        return 0;
    temp = my_compute_power_rec(nb, p - 1);
    number = nb * temp;
    if (number / nb != temp)
        return 0;
    return number;
}
