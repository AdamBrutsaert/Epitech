/*
** EPITECH PROJECT, 2022
** print_horizontal
** File description:
** Implementation of print_horizontal
*/

extern void my_putchar(char c);
extern void my_print_n(char c, unsigned int n);

void print_horizontal(unsigned int size)
{
    my_print_n('*', 2 * size + 1);
    my_print_n(' ', 2 * size - 3 + (size == 1) * 2);
    my_print_n('*', 2 * size + 1);
    my_putchar('\n');
}
