/*
** EPITECH PROJECT, 2022
** my_isneg
** File description:
** Implementation of my_isneg
*/

extern void my_putchar(char c);

int my_isneg(int n)
{
    my_putchar(n < 0 ? 'N' : 'P');
    return 0;
}
