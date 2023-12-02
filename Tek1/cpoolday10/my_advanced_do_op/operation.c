/*
** EPITECH PROJECT, 2022
** operation
** File description:
** Implementation of operation
*/

#include <unistd.h>
#include "my.h"
#include "operation.h"

int my_add(int a, int b)
{
    my_put_nbr(a + b);
    my_putchar('\n');
    return 0;
}

int my_sub(int a, int b)
{
    my_put_nbr(a - b);
    my_putchar('\n');
    return 0;
}

int my_mul(int a, int b)
{
    my_put_nbr(a * b);
    my_putchar('\n');
    return 0;
}

int my_div(int a, int b)
{
    if (b == 0) {
        write(2, "Stop: division by zero\n", 23);
        return 84;
    }
    my_put_nbr(a / b);
    my_putchar('\n');
    return 0;
}

int my_mod(int a, int b)
{
    if (b == 0) {
        write(2, "Stop: modulo by zero\n", 21);
        return 84;
    }
    my_put_nbr(a % b);
    my_putchar('\n');
    return 0;
}
