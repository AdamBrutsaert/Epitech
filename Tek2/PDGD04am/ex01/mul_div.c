/*
** EPITECH PROJECT, 2024
** mul_div.c
** File description:
** mul_div.c
*/

void mul_div_long(int a, int b, int *mul, int *div)
{
    *mul = a * b;
    *div = b == 0 ? 42 : a / b;
}

void mul_div_short(int *a, int *b)
{
    int product = *a * *b;
    int div = *b == 0 ? 42 : *a / *b;

    *a = product;
    *b = div;
}
