/*
** EPITECH PROJECT, 2022
** my_print_combn
** File description:
** Implementation of my_print_combn
*/

extern void my_putchar(char c);

static void print_number_rec(int n, int nb, char step, char last)
{
    if (step == n - 1) {
        my_putchar('0' + nb);
    } else {
        print_number_rec(n, nb / 10, step + 1, last);
        my_putchar('0' + nb % 10);
    }
    if (step == 0 && !last) {
        my_putchar(',');
        my_putchar(' ');
    }
}

static void my_print_combn_rec(int n, int nb, char step, char last)
{
    if (step == 1 && nb == 10 - n)
        last = 1;
    if (step == n) {
        print_number_rec(n, nb, 0, last);
    } else {
        for (int i = nb % 10 + !!step; i <= 9; i++)
            my_print_combn_rec(n, nb * 10 + i, step + 1, last);
    }
}

int my_print_combn(int n)
{
    if (n <= 0 || n > 10)
        return 0;
    my_print_combn_rec(n, 0, 0, 0);
    return 0;
}
