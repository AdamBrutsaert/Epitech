/*
** EPITECH PROJECT, 2022
** check_operation
** File description:
** Implementation of check_operation
*/

int check_mult(int a, int b, char *overflow)
{
    int result = a * b;

    if (a != 0 && result / a != b)
        *overflow = 1;
    return result;
}

int check_add(int a, int b, char *overflow)
{
    char positive = a > 0;
    int result = a + b;

    if (a != 0 && b != 0
        && ((positive && result < 0) || (!positive && result > 0)))
        *overflow = 1;
    return result;
}
