/*
** EPITECH PROJECT, 2022
** print
** File description:
** Implementation of print
*/

extern void my_putchar(char c);

void my_print_n(char c, unsigned int n)
{
    for (unsigned int i = 0; i < n; i++)
        my_putchar(c);
}
