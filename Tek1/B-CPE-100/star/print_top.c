/*
** EPITECH PROJECT, 2022
** print_top
** File description:
** Implementation of print_top
*/

extern void my_putchar(char c);
extern void my_print_n(char c, unsigned int n);

void print_top(unsigned int size)
{
    unsigned int offset = 3 * size - 1 + (size == 1);

    my_print_n(' ', offset);
    my_putchar('*');
    my_putchar('\n');
    for (unsigned int i = 1; i < size; i++) {
        my_print_n(' ', offset - i);
        my_putchar('*');
        my_print_n(' ', 2 * i - 1);
        my_putchar('*');
        my_putchar('\n');
    }
}
