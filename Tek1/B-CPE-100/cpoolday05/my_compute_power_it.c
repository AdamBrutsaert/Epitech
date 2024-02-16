/*
** EPITECH PROJECT, 2022
** my_compute_power_it
** File description:
** Implementation of my_compute_power_it
*/

// Here, we check overflow, by verifying that when we multiply
// and then divide we get the correct number back, if not, it
// means we have an overflow.
int my_compute_power_it(int nb, int p)
{
    int number = 1;
    int temp;

    if (p < 0 || (p && !nb))
        return 0;
    for (; p; p--) {
        temp = number * nb;
        if (temp / number != nb)
            return 0;
        number = temp;
    }
    return number;
}
