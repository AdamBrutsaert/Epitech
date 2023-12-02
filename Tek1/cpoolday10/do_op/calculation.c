/*
** EPITECH PROJECT, 2022
** calculate
** File description:
** Implementation of calculate
*/

#include <unistd.h>
#include "my.h"

// It doesn't handle overflow
int do_add(int a, int b)
{
    my_put_nbr(a + b);
    my_putchar('\n');
    return 0;
}

int do_sub(int a, int b)
{
    my_put_nbr(a - b);
    my_putchar('\n');
    return 0;
}

int do_mul(int a, int b)
{
    my_put_nbr(a * b);
    my_putchar('\n');
    return 0;
}

int do_div(int a, int b)
{
    if (b == 0) {
        write(2, "Stop: division by zero\n", 23);
        return 84;
    }
    my_put_nbr(a / b);
    my_putchar('\n');
    return 0;
}

int do_mod(int a, int b)
{
    if (b == 0) {
        write(2, "Stop: modulo by zero\n", 21);
        return 84;
    }
    my_put_nbr(a % b);
    my_putchar('\n');
    return 0;
}
